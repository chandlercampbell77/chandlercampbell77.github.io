#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int div[8];
    int remainder[8];

    string message = get_string("Message: ");

    for (int j = 0; j < strlen(message); j++)
    {
        // divides each character of the message
        div[0] = message[j] / 2;
        div[1] = div[0] / 2;
        div[2] = div[1] / 2;
        div[3] = div[2] / 2;
        div[4] = div[3] / 2;
        div[5] = div[4] / 2;
        div[6] = div[5] / 2;
        div[7] = div[6] / 2;

        // gets the remainder of each character
        remainder[0] = message[j] % 2;
        remainder[1] = div[0] % 2;
        remainder[2] = div[1] % 2;
        remainder[3] = div[2] % 2;
        remainder[4] = div[3] % 2;
        remainder[5] = div[4] % 2;
        remainder[6] = div[5] % 2;
        remainder[7] = div[6] % 2;

        // goes through each remainder
        for (int i = 7; i >= 0; i--)
        {
            if (remainder[i] == 0)
            {
                // Dark emoji
                printf("\U000026AB");
            }
            else if (remainder[i] == 1)
            {
                // Light emoji
                printf("\U0001F7E1");
            }
        }
        printf("\n");
    }
}