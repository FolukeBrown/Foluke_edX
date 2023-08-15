#include <stdio.h>
/**
 * main - Your program must then display the text "Special tax" or "Regular tax" 
 * followed by the amount you have to pay on the next line.
 * Return: ALways 0 (Success)
 */
int main(void)
{
    int dice1;
    int dice2;
    int sum = 0;
    int otherSum = 0;
    int specialFee = 36;
    printf("Input two numbers from the range of 1-6\n");
    scanf("%d %d", &dice1, &dice2);
    sum = dice1 + dice2;
    if(dice1 && dice2 >=1 && dice1 && dice2 <=6 && sum >= 10)
    {
        printf("Special tax\n %d\n", specialFee);
    } else if(dice1 && dice2 >=1 && dice1 && dice2 <=6 && sum < 10)
    {
        otherSum = (sum * 2);
        printf("Regular tax\n %d\n", otherSum);
    }else
    {
        printf("Your dice input number is invalid\n");
    }
    return (0);
}