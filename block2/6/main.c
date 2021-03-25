#include <stdio.h>

int main() {
    printf("Task 1: \n");
    int task1[6] = {34, 45, 56, 67, 78, 89};
    for (int i = 0; i < 6; i++) {
        printf("%d\n", task1[i]);
    }

    printf("\nTask 2: \n");
    int mas1[2][2] = {{1, 0},
                      {1, 4}};
    int mas2[2][2] = {{1, 2},
                      {0, 1}};
    int masR[2][2] = {{mas1[0][0] * mas2[0][0] + mas1[0][1] * mas2[1][0],
                              mas1[0][0] * mas2[0][1] + mas1[0][1] * mas2[1][1]},
                      {mas1[1][0] * mas2[0][0] + mas1[1][1] * mas2[1][0],
                              mas1[1][0] * mas2[0][1] + mas1[1][1] * mas2[1][1]}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d", masR[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}