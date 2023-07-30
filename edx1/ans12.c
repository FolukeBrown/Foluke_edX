#include<stdio.h>
int main(void){
    float tempCel;
    float tempFeh;
    scanf("%f\n", &tempCel);
    tempFeh = tempCel * 9.0 /5.0 + 32.0;
  
    printf("%.1f\n", tempFeh);
    
    
    
    
    return 0;
}
