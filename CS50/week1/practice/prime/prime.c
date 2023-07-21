#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    // miniumum loop
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);
    // maximum loop
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);
    // check each number min through max
    for (int i = min; i <= max; i++)
    {
        // print the number if it is prime
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // TODO
    // we know this number is not prime
    if (number <= 1)
    {
        return false;
    }

    // we know these numbers are prime
    if (number == 2 || number == 3)
    {
        return true;
    }
    // check to see if each number is prime
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }

    }
    return true;
}
