#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

char KEY[26];

// string cipher(string word);

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
        // printf("User Key: %s\n", key);

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
                    int count = 26;

                    for (int j = 0; j < count - 1; j++)
                    {
                        for (int k = j + 1; k < count; k++)
                        {
                            if (key[j] == key[k])
                            {
                                printf("Your key contains duplicate letters\n");
                                return 1;
                            }
                        }
                    }
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
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            char c = plaintext[i];
            if (isalpha(c))
            {
                if (isupper(c))
                {
                    int digit = (int) c - 65;
                    plaintext[i] = toupper(KEY[digit]);
                }
                else
                {
                    int digit = (int) c - 97;
                    plaintext[i] = tolower(KEY[digit]);
                }
            }
        }
        //TODO Print ciphertext
        printf("ciphertext: %s\n", plaintext);
    }
    return 0;
}
