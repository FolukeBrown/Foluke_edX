#include <stdio.h>
/**
* main -program should then print the cost that you have to pay (a decimal number) with 2 digits after the decimal point
* Return: ALways 0 (Success)
*/
int main(void)
{
int passenger;
double costOfGas;
double totalCost = 0;

printf("Enter the number of passengers followed by the cost of gas\n");
scanf("%d", &passenger);
scanf("%lf", &costOfGas);


if (passenger == 0)
{
totalCost = costOfGas;
printf("The total cost of your trip is %.2lf\n", totalCost);
}
else if (passenger > 0)
{
totalCost = (costOfGas + 1.0) / (passenger + 1);

printf("The total cost of your trip is %.2lf\n", totalCost);
}
return (0);
}
