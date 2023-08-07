#include <stdio.h>
#define NEWLINE 7

/**
 * main - This program prints the decimal
 * conversion of the ascii values
 * Return: 0 for success
 */

int printer(int num);
int main (void)
{
	int digits = 32, res;

	printf("\n\t\tASCII-TABLE(CONVERSION FROM DIGITS TO CHARACTERS)\n\n");

	for (; digits <= 127; digits++)
	{
		if (digits <= 34)
			res = printer(digits);

		else if (digits >= 35 && digits <= 99)
			res = printer(digits);

		else
			res = printer(digits);

		if (res)
		{
			printf("\n");
			if (digits == 99)
				printf("\n");
		}
	}
	printf("\nB😎\n");
	return (0);
}

int printer (int num)
{
	int newline;

	printf("%d = '%c' | ", num, num);
	if ((num + 1) % NEWLINE == 0)
		printf("\n");

	newline = (num == 34 || num == 99 || num == 127) ? 6 : 0;

	return (newline);
}
