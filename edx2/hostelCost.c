#include<stdio.h>
/**
 * main - program should print the price (an integer) you have to pay, given the input arrival time
 * Return: ALways 0 (Success)
 */
int main (void) 
{
    int hourPast;
    int price = 10;
    int tripCost;
    int maxCost = 53;
    printf("How many hours past noon did you arrive?\n");

    scanf("%d\n", &hourPast);
    if (hourPast >= 0 && hourPast <= 8)
    {
        tripCost = price + (hourPast * 5);
    }
    else
    {
        tripCost = maxCost;
    }
    printf ("%d\n", tripCost);

    return (0);
}