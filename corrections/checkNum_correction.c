#include<stdio.h>

void checkNum(){ //here i declared a function checkNum which has a void return value
    int num; //declared num here
printf("What number comes to mind babe?\n");
	/* The number "Foluke" comes to mind every gaddemn time babe😍 */
scanf("%d", &num);//this is to receive an input from a user

//the code below is an if statement that checks a condition if it is true or false
if(num < 0){
    printf("The number you've written is %d which is less than 0\n", num);
} else if(num == 0){
        printf("The number you've written is %d which is equal to 0\n", num);
} else if(num > 0){
    printf("The number you've written is %d which is greater than 0\n", num);
    }
    //the code below is futher checking if my input is in 10,100 or 1000
    if(num >10 && num <= 99){
    printf("The number you've written is %d which is in tens\n", num);
}  else if (num >100 && num <=999){
   printf("The number you've written is %d which is in hundreds\n", num);
   } else if (num >1000 && num <=9999){
   printf("The number you've written is %d which is in thousands\n", num);
   }

}
//in the following code I called the function and passed the value of 'num' into it and I also initialize num to be 0.
   int main(){
int num = 0;
checkNum(num);
return 0;
   }


/**
 * NOTE: THIS IS A MULTI LINE COMMENT
 *
 * 1. This is fantastic babe. Only issue is that the comments are not
 * organised. Imagine that you are writing a thousand lines of code.
 *
 * 2. I think you should avoid using the "//" for commenting. Unless
 * you absolutely have to.
 *
 * 3. Instead of the "//" comments. You should use a summary description
 * always and they should only appear above every function. Just describe
 * the functions, its parameters and return value.
 *
 * 4. Lines 5, 6, 9, 27, 28, 29, 30, 31 are improperly indented. Use tab
 * key for it accordingly.
 *
 * 5. The strings in your print statements are too excessive(Remember,
 * users are lazy to read). Lengthy information may discourage them from
 * using your program.
 *
 * 6. On line 28. You didn't have to initialize num, since the user will
 * supply a value for it.
 *
 * 7. The function "checkNum" takes no argument but you supplied one
 * to it, it's wrong.
 *
 * 8. You placed the main function below the checkNum function, This is
 * bad practice?(imagine if you had a thousand functions, you'd have
 * to scroll down till forever before you see the main function and
 * have a sense of what the program does). Consider placing the
 * main function above all functions and using a prototype.
 */

// lastly, the way i wrote the correction is preffered to tbis one of "//"
/* You could use this for single line comments */


/**
 * I know that you already know about some or most of these tbings
 * i mentioned but i just like to say it regardless 😜
 * I also hope you understand and know how and why to use header
 * files like main.h
 * We will still get to that anyways.
 */
