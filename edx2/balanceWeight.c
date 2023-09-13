#include<stdio.h>
/**
 * program should first read the number of cars to be weighed (integer)
 * followed by the weights of the cars (doubles)
 * program should calculate and display how much weight to add or subtract from each car 
 * such that every car has the same weight.
 * The total weight of all of the cars should not change
 * Return: ALways 0 (Success)
*/
int main(void)
{
    int numBoxcars;
    double weight[50];
    double totalWeight = 0;
    double weightAdjustment = 0;
    double weightPerBoxcars = 0;
    int i = 0;

    printf("Input the number of cars we are weighing\n");
    scanf("%d", &numBoxcars);
    printf("Input the weight of each boxcar\n");
    for(i =0; i < numBoxcars; i++)
    {
        scanf("%lf", &weight[i]);
        totalWeight += weight[i];
    }
    weightPerBoxcars = totalWeight / numBoxcars;

    for(i =0; i < numBoxcars; i++)
    {
    weightAdjustment = weightPerBoxcars - weight[i];
    printf("%.1lf\n", weightAdjustment);    
    }
    return (0);
}