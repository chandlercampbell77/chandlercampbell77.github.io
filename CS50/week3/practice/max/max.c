// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);
int min(int array[], int n);

int main(void)
{
    // getting number of elements in array
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    // creating an array of number of elements
    int arr[n];

    // prompting user for values of elements within the array
    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    // printing
    printf("The max value is %i.\n", max(arr, n));
}

// return the max value
int max(int array[], int n)
{
    // Creating swap variable
    int swap;
    // iterating over number of numbers
    for (int i = 0; i < n - 1; i++)
    {
        // iterating over number of numbers still unsorted
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                // swapping temps since out of order
                swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
            }
        }
    }
    // returning the largest value
    return array[n - 1];
}

// return the min value
int min(int array[], int n)
{
    // Creating swap variable
    int swap;
    // iterating over number of numbers
    for (int i = 0; i < n - 1; i++)
    {
        // iterating over number of numbers still unsorted
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                // swapping temps since out of order
                swap = array[j];
                array[j] = array[j + 1];
                array[j + 1] = swap;
            }
        }
    }
    //returning the smallest value
    return array[0];
}