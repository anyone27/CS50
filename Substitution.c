#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
//#include <strings.h>

char KEY[26];

int main (int argc, string argv[])
{

    // validate user input has 2 arguments
    if (argc != 2)
    {
        printf("missing command-line argument, please input key\n");
        return 1;
    }
    else
    {
        string key = argv[1];
        printf("User Key: %s\n", key);
        //TODO Validate Key
        // 26 alphabetic characters non-repeated
        if (strlen(key) == 26)
        {
            for (int i = 0, n = strlen(key); i < n; i++)
            {
                char c = key[i];
                if (isalpha(c))
                {
                    KEY[i] = c;
                    // printf("KEY: %c\n", KEY[i]);
                }
                else
                {
                    printf("Key contains non-alphabetic characters\n");
                    return 1;
                }
            }
        }
        else
        {
            printf("Key does not contain all 26 letters\n");
            return 1;
        }
        //TODO Get plaintext
        string plaintext = get_string("plaintext: ");

        //TODO Encipher string
        string cipher = NULL;
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            string letter = tolower(plaintext[i]);
            printf("Letter: %s\n", letter);
            int digit = (int)letter - 97;
            cipher[i] = KEY[digit];
            printf("Ciphertext: %s\n", cipher);
            printf("Ciphertext character: %c\n", (char) cipher);
        }
        // string ciphertext = cipher(plaintext);

        //TODO Print ciphertext
        printf("Ciphertext: %s\n", cipher);
        // return cipher;
        return 0;
    }
}
