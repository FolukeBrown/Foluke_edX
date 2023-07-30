#include<stdio.h>
int main(void){
//I will be initializing and declaring my variables straight in a line
int num;
int unit = num % 10; // % is called a modulus operator, it calculate a remainder, it will calculate the remainder when num is divided by 10
int ten = (num/10) %10; //this will tell me the tens place digit
int hundred = (num/100) %10; //this will me the the hundreds place digit
int thousand =(num/1000) %10; // this will equally tell me the thousands place digit

//in this line of code i will be using printf to ask the for a number in thousands and scanf to receive an input from the user.
printf("Please enter a number in thousands: \n");
scanf("&d", &num); //%d is a format specifer, we have %s, %f,%c,%p and many other. while the & before the num is called ampersand, it tell us that the user input should be stored in num if I am correct.

//now I will be using my if statement to check the conditions you've given my life Mr Dafe.
if((unit+hundred) > 5){
    printf("smile for me\n"); //what will you do if I dont smile for you Mr man?
			      /* Ha! I'd kuku prefer that you kee me o😂. The heart ache would be worse o😂 */
} else{
printf("I am beautiful\n");
}
if((ten+thousand) <= 7){
    printf("I won't give up\n");
} else{
printf("God gat me\n"); //always love.
			/* Definitely babe😍 */
}

return 0;
}


/**
 * 1. Beautiful work babe😍
 *
 * 2. Your function has no description.
 *
 * 3. There should be blank line between the header file(s) and other
 * thing(in this case, the main function) for readerbility.
 *
 * 4. Lines 3-26 are improperly indented. Use tab key for it accordingly.
 *
 * 5. On line 5, you don't need to declare and/or initialize unit
 * anymore, Since if the input is a single digit, num%10 will give the
 * same thing.
 *
 * 6. On line 6, e.g 73. num/10 would give you 7 and num%10 would give you 3.
 *
 * 7. On line 7, e.g 269. num/100 would give you 2, (num%100)/10 would give
 * you 6 and num%10 would give you 9.
 *
 * 8. On line 8, e.g 3481. num/1000 would give you 3. (num%1000)/100 will
 * give you 4. ((num%1000)%100)/10 would give you 8 and num%10 would give
 * you 1.
 *
 * 9. The reason why your function prints the same answer for every input
 * is that unit, ten, hundred and thousand will always have the first number
 * of the input the user supplies. e.g for 8, unit=8. for 63, ten=6.
 * for 392, hundred=3. for 9371, thousand=9.
 *
 * 10. You should always check your input to determine if the value the
 * user entered is a unit, ten, hundred or thousand and then use that
 * value accordingly.
 *
 * I know that you already know about some or most of these things
 * i mentioned but i just like to say it regardless 😜
 */
