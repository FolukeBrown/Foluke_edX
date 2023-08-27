#include<stdio.h>
/**
 * a program that will give you the name of the tree based on its characteristics.
 * program should read the height and the number of leaflets of a given tree
 * and should be able to determine and display the name of the corresponding tree.
 * Return: ALways 0 (Success)
*/
int main(void)
{
   int height;
   int numOfLeaflets;
    printf("What is the height of the tree and how many leaflets does it have\n");
    scanf("%d %d", &height, &numOfLeaflets);
        if(height <= 5 && numOfLeaflets >= 8)
        {
            printf("Tinuviel\n");
        }
        else if(height >= 10 && numOfLeaflets >= 10)
        {
            printf("Calaelen\n");
        }
        else if(height <= 8 && numOfLeaflets <= 5)
        {
            printf("Falarion\n");
        }
        else if(height >= 12 && numOfLeaflets <= 7)
        {
            printf("Dorthonion\n");
        }
        else
        {
            printf("Uncertain\n");
        }
    return (0);
}