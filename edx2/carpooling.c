#include <stdio.h>
/**
* main - rogram should then print the cost that you have to pay (a decimal number) with 2 digits after the decimal point
* Return: ALways 0 (Success)
*/
int main(void)
{
int passenger;
double costOfGas;
double totalCost = 0;

scanf("%d", &passenger);
scanf("%lf", &costOfGas);


if (passenger == 0)
{
totalCost = costOfGas;
printf("%.2lf\n", totalCost);
}


else if (passenger > 0)
{
totalCost = (costOfGas + 1.0) / (passenger + 1);

printf("%.2lf\n", totalCost);
}



return (0);
}
