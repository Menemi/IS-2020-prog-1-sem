#include <stdio.h>

int main() {
    float temp;
    printf("Input float number: ");
    scanf("%f", &temp);
    printf("You typed this number: %f\n\n", temp);

    char temp2;
    printf("Input symbol: ");
    scanf("%c", &temp2);
    printf("You typed this symbol: %c\n", temp2);
}