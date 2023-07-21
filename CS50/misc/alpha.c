#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string word = get_string("Word: ");
    int length = strlen(word);
    int i = 0;

    for (int element = 0; element < length - 1; element++)
    {
        if (word[element] < word[element + 1])
        {
            i++;

            if (i == length - 1)
            {
                printf("Yes\n");
            }
        }
        else
        printf("No\n");
    }
}