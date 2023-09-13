#include<stdio.h>
/**
 * store recipe ingredients in an array
 * program must read 10 integers and store them in an array
 * should then read an integer which represents an ingredient's ID number
 * program output the corresponding quantity.
*/
int main(void)
{
    int quantity[10];
    int readQuantity = 0;
    int ingredientId = 0;
    int i = 0;
     printf("What is the quantity of the 10 ingredients?\n");
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &readQuantity);
        quantity[ingredientId] = readQuantity;
        ingredientId = ingredientId + 1;
    }
        printf("What ingredient quantity do you require?\n");
        scanf("%d", &ingredientId);
        printf("%d\n", quantity[ingredientId]);
    return (0);
}

