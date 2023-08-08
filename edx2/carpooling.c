#include <stdio.h>
int main(void){
    int passenger;
    double costOfGas;
    double totalCost =0;
    int i;
    
    scanf("%d", &passenger);
    scanf("%lf", &costOfGas);
    
   
    if (passenger == 0){
         totalCost=costOfGas;
          printf("%.2lf\n", totalCost);
    }
   
    
    else{
    for (i=0; passenger > 0; i++){
         
    }
    totalCost = (costOfGas+1.0)/passenger;
   
        printf("%.2lf\n", totalCost);
    }
       
    
    
    return 0;
}