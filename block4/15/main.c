#include <stdio.h>
#include <string.h>

void create(char *file1, int argc, char *argv[]) {
    FILE *arc = fopen(file1, "wb");
    FILE *file2;
    unsigned long long int _size_[128];
    for (int i = 4; i < argc; i++) {
        file2 = fopen(argv[i], "rb");
        if (file2 == NULL)
            continue;
        fseek(file2, 0, SEEK_END);
        _size_[i - 4] = ftell(file2);
        fseek(file2, 0, SEEK_SET);
        fclose(file2);
    }
    for (int i = 0; i < argc - 4; i++)
        fprintf(arc, "%s - %llu\n", argv[i + 4], _size_[i]);
    fprintf(arc, " ");
    for (int i = 4; i < argc; i++) {
        file2 = fopen(argv[i], "rb");
        if (file2 == NULL) {
            printf("Can't open %s for reading\n", argv[i]);
            continue;
        } else
            printf("File %s added\n", argv[i]);
        while (getc(file2) != EOF)
            putc(getc(file2), arc);
        fclose(file2);
    }
}

void list(char *file1) {
    FILE *file = fopen(file1, "rb");
    char temp[128];
    for (int i = 0; i < 2; i++) {
        fscanf(file, "%s", temp);
        printf("%s\n", temp);
        fscanf(file, "%s", temp);
        fscanf(file, "%s", temp);
    }
    fclose(file);
}

void extract(char *file1) {
    FILE *file = fopen(file1, "rb+");
    unsigned long long int start = 0;
    unsigned long long int end = 0;
    int temp;
    while ((temp = getc(file)) != EOF) {
        start++;
        if (temp == '\n')
            break;
    }
    fseek(file, 0, SEEK_SET);
    char file2[128] = {0};
    char rubbish[128] = {0};
    unsigned long long int sizefl;
    FILE *outfl;
    for (int i = 0; i < 2; i++) {
        fscanf(file, "%s%s%llu", file2, rubbish, &sizefl);
        outfl = fopen(file2, "wb");
        if (outfl == NULL)
            break;
        end = ftell(file);
        fseek(file, start, SEEK_SET);
        start += sizefl;
        while ((sizefl--) > 0)
            putc((temp = getc(file)), outfl);
        fseek(file, end, SEEK_SET);
        fclose(outfl);
    }
    printf("DONE!\n");
}

int main(int argc, char *argv[]) {
    char *file1;
    printf("\n");
    for (int i = 0; i < argc; i++) {
        if (!strcmp("--file", argv[i]))
            file1 = argv[i + 1];
        if (!strcmp("--create", argv[i])) {
            create(file1, argc, argv);
            break;
        }
        if (!strcmp("--extract", argv[i]))
            extract(file1);
        if (!strcmp("--list", argv[i]))
            list(file1);
    }
}