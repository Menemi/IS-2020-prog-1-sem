#include <stdio.h>

int length(char str[100])
{
	int count = 0;

	for (int i = 0; i < 100; i++)
	{
		if (str[i] != '\0') count++;
		else return count;
	}
	return count;
}

int isNumber(char symbol)
{
	if (symbol >= '0' && symbol <= '9')
	return 0;
}

int isPropis(char symbol)
{
	if (symbol >= 'A' && symbol <= 'Z')
	return 0;
}

int isStroch(char symbol)
{
	if (symbol >= 'a' && symbol <= 'z')
	return 0;
}

int main()
{
	char* str = new char[100];
	printf("Input any string: ");
	gets(str);

	int resN = 0;
	int resP = 0;
	int resS = 0;

	for (int i = 0; i < length(str); i++)
	{
		if (isNumber(str[i]) == 1) resN++;
		else if (isPropis(str[i]) == 1) resP++;
		else resS++;
	}

	printf("\n");
	printf("1. Count of numbers: %d\n", resN);
	printf("2. Count of uppercase letters: %d\n", resP);
	printf("3. Count of lowercase letters: %d\n", resS);

	printf("\n");
	int temp;
	printf("Input any number (0-9): ");
	scanf("%d", &temp);

	switch (temp)
	{
	case 0:
		printf("Zero");
		break;
	case 1:
		printf("One");
		break;
	case 2:
		printf("Two");
		break;
	case 3:
		printf("Three");
		break;
	case 4:
		printf("Four");
		break;
	case 5:
		printf("Five");
		break;
	case 6:
		printf("Six");
		break;
	case 7:
		printf("Seven");
		break;
	case 8:
		printf("Eight");
		break;
	case 9:
		printf("Nine");
		break;
	default:
		break;
	}
}