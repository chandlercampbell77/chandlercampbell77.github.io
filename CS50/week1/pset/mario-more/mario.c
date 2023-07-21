#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // asks user for height
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);

    // height of pyramid
    for (int i = 0; i < height; i++)
    {
        // spaces

        for (int j = height - 1; j > i ; j--)
        {
            printf(" ");
        }

        // hashes

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");

        // hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");

    }
}