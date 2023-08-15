#include <stdio.h>
int main(void){
    int passenger;
    double costOfGas;
    double totalCost =0;
    
    scanf("%d", &passenger);
    scanf("%lf", &costOfGas);
    
   
    if (passenger == 0){
         totalCost=costOfGas;
          printf("%.2lf\n", totalCost);
    }
   
    
    else if (passenger > 0){
    totalCost =(costOfGas+1.0)/(passenger +1) ;
   
        printf("%.2lf\n", totalCost);
    }
       
    
    
    return 0;
}