#include<stdio.h>
int main(void){
    double money;
    double pricePer;
    double books;
    int manyBooks;
    scanf("%lf\n", &money);
    scanf("%lf\n", &pricePer);
    books = money / pricePer;
    
    manyBooks = (int)books;
    
    printf("%d\n", manyBooks);
    
    return 0;
}
