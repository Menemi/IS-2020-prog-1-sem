#include <stdio.h>

void razdelitel() {
    printf("\n\n");
    printf("====================================================================================");
    printf("\n\n");
}

int length(char str[100]) {
    int count = 0;

    for (int i = 0; i < 100; i++) {
        if (str[i] != '\0') count++;
        else return count;
    }
    return count;
}

int countOfUniqueSymbols(char str1[100], char str2[100]) {
    int count = 0;
    int S1 = length(str1);
    int S2 = length(str2);

    for (int i = 0; i < S1; i++) {
        int tempCount = 0;
        for (int j = 0; j < S2; j++) {
            if (str1[i] == str2[j]) tempCount++;
        }
        if (tempCount == 0) count++;
    }

    return count;
}

int main() {
    char str1[100] = "hello ";
    char str2[100] = "world ";
    char str3[100] = " ";

    printf("Input str1: ");
    gets(str1);
    printf("Input str2: ");
    gets(str2);

    //3
    if (str1 == str2) printf("str1 = str2");
    else if (str1 < str2) printf("str1 < str2");
    else printf("str1 > str2");
    razdelitel();

    //6
    int n;
    int count;
    int variant;
    printf("Choose which string do you want to + to another: \n");
    printf("1. str1 += str2\n");
    printf("2. str2 += str1\n");
    printf("Input the number (1/2) you`ve choosen: ");
    scanf("%d", &variant);
    printf("Input how many symbols do you want to copy from one string to another: ");
    scanf("%d", &n);

    if (variant == 1) {
        count = length(str1);
        for (int i = 0; i < count; i++) {
            str3[i] = str1[i];
        }
        for (int i = 0; i < n; i++) {
            str3[count + i] = str2[i];
        }
        printf("str1 + %d element(s) of str2: %s", n, str3);
    } else {
        count = length(str2);
        for (int i = 0; i < count; i++) {
            str3[i] = str2[i];
        }
        for (int i = 0; i < n; i++) {
            str3[count + i] = str1[i];
        }
        printf("str2 + %d element(s) of str1: %s", n, str3);
    }
    razdelitel();

    //9
    /*char symbol;
    printf("Input any symbol: ");
    scanf("%c", &symbol);
    int temp = -1;

    for (int i = length(str1)-1; i >= 0; i--)
    {
        if (str1[i] == symbol)
        {
            temp = i;
            break;
        }
    }
    printf("The last index in str1 with your symbol is: %d", temp);
    razdelitel();*/


    //12
    int result12 = countOfUniqueSymbols(str1, str2);
    printf("The count of symbols which is in str1 but not in str2: %d", result12);
    razdelitel();

    //13
}