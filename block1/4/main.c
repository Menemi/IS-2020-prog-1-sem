#include <stdio.h>

int main()
{
	int temp;
	printf("Input the number: ");
	scanf("%d", &temp);
	printf("If YOUR NUMBER is between [6;9] you will see '1', else '0':\n%d\n",
		(temp >= 6 && temp <= 9));

	// 2^26 = 67108864
	printf("\n\nInput new one number(10): ");
	scanf("%d", &temp);
	printf("The 26 bit of your number is: %d \n", (temp >> 26) % 2);
}
