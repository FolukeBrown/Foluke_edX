#include<stdio.h>
int main(void){
    int currentpop;
    double projectedpop;
    double total;
    int totalint;
    scanf("%d\n", &currentpop);
    scanf("%lf\n", &projectedpop);
    
    
    total = currentpop * (1 + (projectedpop/100));
    
    totalint = (int)total;
    printf("%d\n", totalint);
    
    
    return 0;
}
