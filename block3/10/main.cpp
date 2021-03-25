#include <stdio.h>
#include <math.h>

int NOD(int a, int b) {
    while (a > b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

int NOK(int a, int b) {
    return (abs(a * b) / NOD(a, b));
}

int *creatingArray(int n, int count) {
    int *arr = new int[count];

    for (int i = count - 1; i >= 0; i--) {
        arr[i] = n % 10;
        n /= 10;
    }

    return arr;
}

int main() {
    int a, b;
    printf("Input two any integer numbers: ");
    scanf("%d%d", &a, &b);

    printf("NOD of your numbers: %d\n", NOD(a, b));
    printf("NOK of your numbers: %d\n\n", NOK(a, b));

    int n;
    printf("Input any integer number: ");
    scanf("%d", &n);

    int i = 0;
    int temp = n;
    do {
        temp /= 10;
        i++;
    } while (temp > 0);

    int *mas = creatingArray(n, i);

    printf("Array[");
    for (int j = 0; j < i; j++) {
        if (j != i - 1) printf("%d, ", mas[j]);
        else printf("%d]", mas[j]);
    }
}