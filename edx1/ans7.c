#include<stdio.h>
int main(void){
    int i;
    int number = 0;
    int multiplyBy;
    int result = 0;
    scanf("%d", &multiplyBy);
    for(i=0; i<11; i++){
        printf("%dx%d = %d\n", number, multiplyBy, result);
        number = number + 1;
        result = number * multiplyBy;
    }
    
    
 return 0;   
}
