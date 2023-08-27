#include<stdio.h>
/**
 * program that will easily allow you and your travel companions to know the price of one night.
 * program should read the customer's age first, then the weight of their luggage,
 * then output the price they have to pay.
 * complex logic conditions to find hostel cost
 *  Return: ALways 0 (Success)
*/
int main(void)
{
    int luggageWeight;
    int customerAge;
    int totalPrice = 0;
    int roomPrice = 30;
    int luggagePrice = 10;

    printf("Please input your age followed by the weight of your luggage\n");
    scanf("%d %d", &customerAge, &luggageWeight);

    if(customerAge == 60 && luggageWeight > 0)
    {
        printf("%d\n", totalPrice);
    }
    else if(customerAge < 10 && luggageWeight > 0)
    {
        printf("%d\n", totalPrice + 5);
    } 
    else if(customerAge >= 10)
    {
        if(luggageWeight <= 20)
        {
            printf("%d\n", roomPrice);
        }
    
        else if(customerAge >= 10 && luggageWeight > 20)
        {
            totalPrice = roomPrice + luggagePrice;
            printf("%d\n", totalPrice);
        }
    }
    return (0);
}