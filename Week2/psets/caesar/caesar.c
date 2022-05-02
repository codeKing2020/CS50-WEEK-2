#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int key = 0;
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            // Numbers in ASCII range from 48 to 57
            if (argv[1][i] < 48 || argv[1][i] > 57)
            {
                printf("Usage: ./caesar key\n");
                // When you return 1, it terminates the whole loop,, but doens't display on the terminal
                return 1;
            }
            else
            {
                /* By changing the value of this variable, 
                    you don't add, subtract or do anything to the command-line argument 
                    it stays the same until the loop is finished.*/
                key = atoi(argv[1]);
            } 
        }
        /* And then we use an if statement to check if the key has changed. 
        If it hasn't, nothing happens, if it did, It displays "success". 
        We continue from this if statemnt to finish the rest of the caesar */
        if (key >= 1)
        {
            // Prompt user for plaintext
            string plaintext = get_string("plaintext: ");
            
            // Encipher
            // Convert ASCII to alphabetical index
            // convert results back to ascii
            // Then print out answer
            printf("ciphertext: ");
        
            for (int i = 0, n = strlen(plaintext); i < n; i++)
            {
                // variable that stores everything
                char convert = plaintext[i];
                 
                //If it is uppercase
                if (isupper(convert))
                {
                    //Take that letter and deduct by 65 then add by key and then give the remainder when divided by 26 and then add 65 again to give me the changed character
                    // For example: convert = (('C' - 'A' + 2) %26) + 'A'; This equals to 'E' , because ((67 - 65 + 2) % 26) + 65 = 69;
                    convert = ((convert - 'A' + key) % 26) + 'A';
                }
                //Else If it is lowercase
                else if (islower(convert))
                {
                    //Take that letter and deduct by 97 then add by key and then give the remainder when divided by 26 and then add 97 again to give me the changed character
                    // For example: convert = (('a' - 'a' + 2) %26) + 'a'; This equals to 'c' , because ((97 - 97 + 2) % 26) + 97 = 99;
                    convert = ((convert - 'a' + key) % 26) + 'a';
                }
                // The answer
                printf("%c", convert);
            }
            printf("\n");
            return 0;
        }
        
    }
    else
    {
        printf("Usage: ./caesar key\n");
    }
    return 1;
}