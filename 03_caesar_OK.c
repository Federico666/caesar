#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int array_uc[26] = {0};
    int array_lc[26] = {0};
    int k = 0;
    int ci = 0;
    
    //Create two arrays with upper and lower case ascii letters
    for (int i = 0; i < 26; i++)
    {
        array_uc[i] = 'A' + i;
        array_lc[i] = 'a' + i;
    }

    //If there are only 2 arguments and argv[1] is greater than 0, continue
    if (argc == 2 && argv[1] > 0)
    {
        //Itirate the 2nd element of the command line array,the array of char argv[1]
        for (int i = 0 ; i < strlen(argv[1]) ; i++)
        {
            //Check ASCII table between (49 = 1) and (57 = 9)
            if (argv[1][i] < 49 || argv[1][i] > 57)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        //atoi function of stdlib converts a array of numbers into that number itself
        k = atoi(argv[1]);
    }
    //Else, show error message
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
  
    //Get the plaintext from user and store it as ptext string
    string ptext = get_string("plaintext: ");
    //Get lenght of plaintext string and store it as n
    int n = strlen(ptext);
  
    //Itirate ptext string
    for (int i = 0 ; i < n ; i++)
    {
        //If ptext[i] is Uppercase (between 65 & 90), use array_uc to compare
        if (ptext[i] >= 'A' && ptext[i] <= 'Z')
        {
            ci = ((ptext[i] - 65) + k) % 26;
            ptext[i] = array_uc[ci];
        }
        //Else if plainttext[i] is Lowercase (between 97 & 122), use array_lc to compare
        else if (ptext[i] >= 'a' && ptext[i] <= 'z')
        {
            ci = ((ptext[i] - 97) + k) % 26;
            ptext[i] = array_lc[ci];
        }
    }

    printf("ciphertext: %s\n", ptext);
  
}