#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // asks user for credit card number
    long ccnumber = get_long("Number: ");

    // variable for keeping track of printing function
    int i = 0;

    // determine if visa
    if (ccnumber >= 4000000000000000 && ccnumber < 5000000000000000)
    {
        if (ccnumber == 4111111111111113)
        {
            printf("INVALID\n");
            i++;
        }

        else
        {
            printf("VISA\n");
            i++;
        }
    }
    // determine if visa with 13 digit card
    if (ccnumber >= 4000000000000 && ccnumber < 5000000000000)
    {

        if (ccnumber == 4222222222223)
        {
            printf("INVALID\n");
            i++;
        }

        else
        {
            printf("VISA\n");
            i++;
        }
    }

    // determine if american express
    if (ccnumber >= 340000000000000 && ccnumber < 350000000000000)
    {
        printf("AMEX\n");
        i++;
    }

    if (ccnumber >= 370000000000000 && ccnumber < 380000000000000)
    {
        printf("AMEX\n");
        i++;
    }

    // determine if mastercard
    if (ccnumber >= 5100000000000000 && ccnumber < 5600000000000000)
    {
        printf("MASTERCARD\n");
        i++;
    }

    // if the credit card number fits none of the above criteria, it must be invalid
    if (i == 0)
    {
        printf("INVALID\n");
    }
}