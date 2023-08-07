#include <stdio.h> 
#include <string.h>

/**
 * main - This program is used to encrypt and decrypt
 * codes that are written strictly in alphabets and
 * follows the rot13 standard format
 *
 * Return: 0 for success
 */


char *cipher (char *par);
int loopFunc (void);
int charCounter (char *cou);

int main() 
{
	int numLoop;

	printf("Enter a text\nIN>>>  ");
	numLoop = loopFunc ();
	printf("\nYou performed %d cipher operation(s)\n", numLoop);
	printf("Cheers 😎\n");

	return 0; 
}





/**
 * cipher - this function counts the number of input characters and
 * converts it into gibberish accordingly, based on the rot13 
 * standard format
 *
 * @par: the user input
 * Return: the converted string
 */
char *cipher (char *par)
{
	int i=0;
	char *str, *rot;
        str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        rot = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
                                                                                          while (par[i] != '\0')
        {                                                                                         for(int n=0; n<52; n++)
                {
                        if(par[i] == str[n])
                        {
                                par[i] = rot[n];
                                break;
                        }
                }
                i++;
	}
	return par;
}



/**
 * loopFunc - the function that takes care of the loop
 */
int loopFunc (void)
{
	char *crypt, user[1001];
	int counter, i=0;

	while (1)
	{
		if (i != 0)
			printf("Go again. Use \"q\" to quit\nIN>>>  ");

		//scanf("%50s", user);
		fgets (user, sizeof(user), stdin);

		if ((strlen(user)-1)==1 && *user=='q')
			break;
		
		crypt = cipher (user);
		counter = charCounter (user);

		printf("OUT>>  %s", crypt);
		printf("You entered %d characters.\n\n", counter);
		i++;
	}
	return i;
}



/**
 * charCounter - this function counts the number of characters
 * the user enters
 */
int charCounter (char *cou)
{
	int numChars = (strlen (cou) - 1);
	return numChars;
}
