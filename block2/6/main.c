#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Task 1: \n");
    float mas[4];
    float *MAS = &mas[0];
    mas[0] = -3.4;
    mas[1] = 4.5;
    mas[2] = -5.6;
    mas[3] = 6.7;
    for (int i = 0; i < 4; i++) {
        printf("%f\n", *(mas + i));
    }

    printf("\nTask 2: \n");
    float *arr = (float *) malloc(4 * sizeof(float));
    arr[0] = -3.4;
    arr[1] = 4.5;
    arr[2] = -5.6;
    arr[3] = 6.7;
    for (int i = 0; i < 4; i++) {
        printf("%f\n", *(arr + i));
    }
}