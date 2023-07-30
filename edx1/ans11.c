#include <stdio.h>
int main (void){
    double distanceKg;
    double kg = 0.621371;
    double distanceMiles;
    
    scanf("%lf", &distanceKg);
    distanceMiles = distanceKg * kg;
    
    printf("%.6lf", distanceMiles);
    
    return 0;
}
