#include<stdio.h>
int main(void){
    
  int loosedmatch = 0;
  int boxes = 0;
 
  scanf("%d\n", &loosedmatch);
  scanf("%d\n", &boxes);
  
  int fullbox = loosedmatch / boxes;
  int rest = loosedmatch % boxes;
  
  printf("%d\n", fullbox);
  printf("%d\n", rest);
  
  
    
    return 0;
}
