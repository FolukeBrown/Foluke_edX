#include<stdio.h>
int main(void){
  int numgrade = 0;
  int grade =0;
  int sum =0;
  double average;
  int i;
  scanf("%d\n", &numgrade);
    for (i=0; i <numgrade; i++){
        scanf("%d\n", &grade);
        
        sum += grade;
    }
    average =(double)sum / numgrade;
    printf("%.2lf\n", average);
    
    return 0;
}
