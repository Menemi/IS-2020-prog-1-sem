#include <stdio.h>

int main() {
    int temp;
    printf("Task 1:\n");
    printf("Input the number(10): ");
    scanf("%d", &temp);

    printf("\nTask 2:\n");
    printf("This number(16): %x", temp);

    printf("\n\nTask 3:\n");
    printf("This number(16): %x", temp);
    printf("\nThis number(16 << 2): %x", temp << 2);

    printf("\n\nTask 4:\n");
    printf("This number(16): %x", temp);
    printf("\nThis number(~16): %x", ~temp);

    printf("\n\nTask 5:\n");
    printf("Input the number(16): ");
    int temp2;
    scanf("%x", &temp2);
    printf("temp xor temp2: %x\n", temp ^ temp2);
}