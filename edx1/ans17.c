#include<stdio.h>
int main(void){
    double cementneed;
    int cementPrice = 45;
    int cementWeight = 120;
    
    scanf("%lf\n", &cementneed);
    int bagneeded = ceil(cementneed / cementWeight);
    int cementcost = bagneeded * cementPrice;
    
    printf("%d\n", cementcost);
    
    
    
    return 0;
}
