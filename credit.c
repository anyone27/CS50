#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int even = 0;
    int odd = 0;
    int i = 0;
    int valid = 0;
    int thirteen;
    int fourteen;
    int fifteen;
    int sixteen;
    long number;

    // prompt user for credit card number
    do
    {
        number = get_long("Number: ");
    }

    // calculate checksum
    while (number < 0);
    {

        //while number greater than 0 modulo number 10 to get each digit
        long num = number;
    while (num > 0)
    {
    int mod = num % 10;

        if (i + 1 == 13)
        {
        thirteen = mod;
        }
        if (i + 1 == 14)
        {
        fourteen = mod;
        }
         if (i + 1 == 15)
        {
        fifteen = mod;
        }
         if (i + 1 == 16)
        {
        sixteen = mod;
        }

        //increment i shows odd or even digits
        if(i % 2 == 0)
        {

            //if even, sum digits
            even = even + mod;
        }
        else
        {

            //if odd, multiply by 2, modulo digits by 10 to split and sum to odd
            int doub = mod * 2;
            while (doub > 0)
            {
                int temp = doub % 10;
                odd = odd + temp;
                doub = doub / 10;
            }
        }

        num = num / 10;
        i++;
    }
    int checksum = odd + even;
    int check = checksum % 10;
    if (check == 0)
    {

        //Check card length and starting digit
        if(i >= 13 && i <= 16)
        {
            // Amex - 15 Digits starting with 34 or 37
            if (i == 15 && fifteen == 3 && (fourteen == 4 || fourteen == 7))
            {
                printf("AMEX\n");
            }

            //MasterCard - 16 Digits, starts with 51, 52, 53, 54 or 55
            else if (i == 16 && sixteen == 5 && (fifteen == 1 || fifteen == 2 || fifteen == 3 || fifteen == 4 || fifteen == 5))
            {
                printf("MASTERCARD\n");
            }

            // Visa - 13 or 16 Digits starting with a 4
            else if((i == 13 || i == 16) && (thirteen == 4 || sixteen == 4))
            {
                printf("VISA\n");
            }

            //Invalid
            else
            {
                printf("INVALID\n");
            }
        }
        else
            {
                printf("INVALID\n");
            }
    }
    else
    {
        valid = 2;
        printf("INVALID\n");
    }
    }
}
