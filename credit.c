#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int even =0;
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
        //printf("mod: %i\n", mod);
        //printf("i: %i\n", i);
        //printf("odd/even: %i\n", i % 2);

        if (i +1 == 13)
        {
            thirteen = mod;
            //printf("thirteen: %i\n", thirteen);
        }
        if (i +1 == 14)
        {
            fourteen = mod;
            //printf("fourteen: %i\n", fourteen);
        }
         if (i +1 == 15)
        {
            fifteen = mod;
            //printf("fifteen: %i\n", fifteen);
        }
         if (i +1 == 16)
        {
            sixteen = mod;
            //printf("sixteen: %i\n", sixteen);
        }

        //increment i shows odd or even digits
        if(i % 2 == 0)
        {
            //if even, sum digits
            even = even + mod;
            //printf("even: %i\n", even);
        }
        else
        {
            //if odd, multiply by 2, modulo digits by 10 to split and sum to odd
            //mod = mod *2;
            int doub = mod * 2;
            //printf("mod x 2: %i\n", doub);
            while (doub > 0)
            {
                int temp = doub % 10;
                odd = odd + temp;
                //printf("odd: %i\n", odd);
                doub = doub/10;
            }
        }

        num = num/10;
        i++;
    }
    int checksum = odd + even;
    printf("checksum: %i\n", checksum);
    int check = checksum % 10;
    printf("Check: %i\n", check);
    if (check == 0)
    {
        //Check card length and starting digit
        if(i>=13 && i<=16)
        {
            // Amex - 15 Digits starting with 34 or 37
            if (i == 15)
            {
                if(fifteen == 3)
                {
                    if((fourteen == 4) || (fourteen == 7))
                    {
                        printf("AMEX\n");
                    }
                }
            }
            //MasterCard - 16 Digits, starts with 51, 52, 53, 54 or 55
            if (i == 16)
            {
                if(sixteen == 5)
                {
                    if((fifteen == 1) || (fifteen == 2) || (fifteen == 3) || (fifteen == 4) || (fifteen == 5))
                    {
                        printf("MASTERCARD\n");
                    }
                }
            }
            // Visa - 13 or 16 Digits starting with a 4
            if((i == 13) || (i == 16))
            {
                if((thirteen== 4) || (sixteen == 4))
                    {
                        printf("VISA\n");
                    }
            }
        }
        //Invalid
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
        printf("\n\n\n");
        printf("number: %li\n", number);
        printf("even: %i\n", even);
        printf("odd: %i\n", odd);
        printf("i: %i\n", i);
        printf("13: %i, 14: %i 15: %i, 16: %i\n", thirteen, fourteen, fifteen, sixteen);

}
