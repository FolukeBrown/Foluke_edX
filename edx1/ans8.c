#include <stdio.h>
int main (void){
    int howMany = 0;
  int enginePower = 0;
  int resistance = 0;
  int weight = 0;
  int height = 0;
  int sum = 0;
  int i=0;
  scanf("%d\n",&howMany);
  
  for(i=0; i<howMany; i++){
      scanf("%d %d %d %d", &height, &weight, &enginePower, &resistance);
  
      sum = sum +((enginePower + resistance)*(weight - height));
  }
      printf("%d\n", sum);
  
    
    
    
    return 0;
}
