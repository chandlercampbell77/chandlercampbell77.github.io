#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Asks user for size
    long n;
    do
    {
        n = get_long("Size: ");
    }
    while (n < 1);

    // Declare our array
    long array[n];

    // Set the first value
    array[0] = 1;
    printf("%li\n", array[0]);

    for (long i = 1; i < n; i++)
    {
        // Make the current element twice the previous
        array[i] = 2 * array[i - 1];

        // Print the current element
        printf("%li\n", array[i]);
    }
}