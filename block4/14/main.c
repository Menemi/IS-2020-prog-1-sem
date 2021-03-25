#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char *fileName;
char *Output = "";

typedef struct {
    char bfType[2];
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} mapFile;

typedef struct {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} mapInfo;

typedef struct {
    int32_t rgbBlue;
    int32_t rgbGreen;
    int32_t rgbRed;
    int32_t rgbReserved;
} rgbColor;

int isAlive(rgbColor pixel) {
    if (pixel.rgbBlue == 0 && pixel.rgbGreen == 0 && pixel.rgbRed == 0)
        return 1;
    else
        return 0;
}

mapFile readBITMAPFILEHEADER(FILE *file) {
    mapFile header;

    fread(&header.bfType, 1, 2, file);
    fread(&header.bfSize, 4, 1, file);
    fread(&header.bfReserved1, 2, 1, file);
    fread(&header.bfReserved2, 2, 1, file);
    fread(&header.bfOffBits, 4, 1, file);

    return header;
}

mapInfo readBITMAPINFOHEADER(FILE *file) {
    mapInfo infoHeader;

    fread(&infoHeader.biSize, 4, 1, file);
    fread(&infoHeader.biWidth, 4, 1, file);
    fread(&infoHeader.biHeight, 4, 1, file);
    fread(&infoHeader.biPlanes, 2, 1, file);
    fread(&infoHeader.biBitCount, 2, 1, file);
    fread(&infoHeader.biCompression, 4, 1, file);
    fread(&infoHeader.biSizeImage, 4, 1, file);
    fread(&infoHeader.biXPelsPerMeter, 4, 1, file);
    fread(&infoHeader.biYPelsPerMeter, 4, 1, file);
    fread(&infoHeader.biClrUsed, 4, 1, file);
    fread(&infoHeader.biClrImportant, 4, 1, file);

    return infoHeader;
}

rgbColor **fieldRGB(FILE *file, mapInfo infoHeader) {
    rgbColor **field = (rgbColor **) malloc(infoHeader.biHeight * sizeof(rgbColor *));

    for (int i = 0; i < infoHeader.biHeight; ++i)
        field[i] = (rgbColor *) malloc(infoHeader.biWidth * sizeof(rgbColor));

    for (int i = infoHeader.biHeight - 1; i >= 0; i--) {
        for (int j = 0; j < infoHeader.biWidth; j++) {
            field[i][j].rgbBlue = getc(file);
            field[i][j].rgbGreen = getc(file);
            field[i][j].rgbRed = getc(file);
        }

        if (infoHeader.biWidth % 4 != 0)
            getc(file);
    }

    return field;
}

void makeBmp(FILE *file, mapFile header, mapInfo infoHeader, rgbColor **pixels) {
    fwrite(&header.bfType, 1, 2, file);
    fwrite(&header.bfSize, 4, 1, file);
    fwrite(&header.bfReserved1, 2, 1, file);
    fwrite(&header.bfReserved2, 2, 1, file);
    fwrite(&header.bfOffBits, 4, 1, file);
    fwrite(&infoHeader.biSize, 4, 1, file);
    fwrite(&infoHeader.biWidth, 4, 1, file);
    fwrite(&infoHeader.biHeight, 4, 1, file);
    fwrite(&infoHeader.biPlanes, 2, 1, file);
    fwrite(&infoHeader.biBitCount, 2, 1, file);
    fwrite(&infoHeader.biCompression, 4, 1, file);
    fwrite(&infoHeader.biSizeImage, 4, 1, file);
    fwrite(&infoHeader.biXPelsPerMeter, 4, 1, file);
    fwrite(&infoHeader.biYPelsPerMeter, 4, 1, file);
    fwrite(&infoHeader.biClrUsed, 4, 1, file);
    fwrite(&infoHeader.biClrImportant, 4, 1, file);

    for (int i = infoHeader.biHeight - 1; i >= 0; i--) {
        for (int j = 0; j < infoHeader.biWidth; j++) {
            putc(pixels[i][j].rgbBlue, file);
            putc(pixels[i][j].rgbGreen, file);
            putc(pixels[i][j].rgbRed, file);
        }

        if (infoHeader.biWidth % 4 != 0)
            putc(0, file);
    }
}

rgbColor **field_to_rgb(int **in, mapInfo infoHeader) {
    rgbColor **field = (rgbColor **) malloc(infoHeader.biHeight * sizeof(rgbColor *));

    for (int i = 0; i < infoHeader.biHeight; ++i)
        field[i] = (rgbColor *) malloc(infoHeader.biWidth * sizeof(rgbColor));

    for (int i = infoHeader.biHeight - 1; i >= 0; i--) {
        for (int j = 0; j < infoHeader.biWidth; j++) {
            if (in[i][j] == 1) {
                field[i][j].rgbBlue = 0;
                field[i][j].rgbGreen = 0;
                field[i][j].rgbRed = 0;
            } else {
                field[i][j].rgbBlue = 255;
                field[i][j].rgbGreen = 255;
                field[i][j].rgbRed = 255;
            }
        }
    }

    return field;
}

int main(int argc, char *argv[]) {
    int max_iter = 100, dump_freq = 1;

    for (int i = 1; i < argc; i += 2) {
        if (strcmp(argv[i], "--input") == 0)
            fileName = argv[i + 1];

        if (strcmp(argv[i], "--output") == 0)
            Output = argv[i + 1];

        if (strcmp(argv[i], "--max_iter") == 0)
            sscanf(argv[i + 1], "%d", &max_iter);

        if (strcmp(argv[i], "--dump_freq") == 0)
            sscanf(argv[i + 1], "%d", &dump_freq);
    }

    FILE *file = fopen(fileName, "r");

    if (file == NULL)
        return 0;

    mapFile header = readBITMAPFILEHEADER(file);

    mapInfo infoHeader = readBITMAPINFOHEADER(file);

    rgbColor **rgb = fieldRGB(file, infoHeader);

    int **gen_old = (int **) malloc(infoHeader.biHeight * sizeof(int *));

    for (int i = 0; i < infoHeader.biHeight; ++i)
        gen_old[i] = (int *) malloc(infoHeader.biWidth * sizeof(int));

    for (int i = 0; i < infoHeader.biHeight; i++)
        for (int j = 0; j < infoHeader.biWidth; j++)
            gen_old[i][j] = (isAlive(rgb[i][j]) == 1 ? 1 : 0);

    int **gen_new = (int **) malloc(infoHeader.biHeight * sizeof(int *));

    for (int i = 0; i < infoHeader.biHeight; ++i)
        gen_new[i] = (int *) malloc(infoHeader.biWidth * sizeof(int));

    for (int i = 0; i < infoHeader.biHeight; i++)
        for (int j = 0; j < infoHeader.biWidth; j++)
            gen_new[i][j] = (isAlive(rgb[i][j]) == 1 ? 1 : 0);

    fclose(file);

    char str[50];
    char path[100];
    int u, l, d, r, neib;

    for (int k = 0; k < max_iter; k++) {
        for (int i = 0; i < infoHeader.biHeight; i++) {
            u = i - 1;
            d = i + 1;

            if (i == 0)
                u = infoHeader.biHeight - 1;

            if (i == infoHeader.biHeight - 1)
                d = 0;

            for (int j = 0; j < infoHeader.biWidth; j++) {
                l = j - 1;
                r = j + 1;

                if (j == 0)
                    l = infoHeader.biWidth - 1;

                if (j == infoHeader.biWidth - 1)
                    r = 0;

                neib = gen_old[u][l] + gen_old[u][j] + gen_old[u][r] + gen_old[i][l] + gen_old[i][r] +
                       gen_old[d][l] + gen_old[d][j] + gen_old[d][r];

                if (gen_old[i][j] == 1) {
                    if (neib < 2 || neib > 3)
                        gen_new[i][j] = 0;

                    else
                        gen_new[i][j] = 1;
                } else {
                    if (neib == 3)
                        gen_new[i][j] = 1;

                    else
                        gen_new[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < infoHeader.biHeight; i++)
            for (int j = 0; j < infoHeader.biWidth; j++)
                gen_old[i][j] = gen_new[i][j];

        if (k % dump_freq == 0) {
            memset(str, 0, 50);
            memset(path, 0, 100);
            sprintf(str, "%d.bmp", k);
            strcpy(path, Output);
            strcat(path, str);

            file = fopen(path, "w");

            makeBmp(file, header, infoHeader, field_to_rgb(gen_old, infoHeader));
            fclose(file);
        }
    }
}