#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

// function declaration
float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    // asks user for weeks evaluated
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        // asks user for HW hours per week
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        // asks user whether they want total hours or average hours
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    int totalhours = 0;

    // calculates total hours spent on cs50
    for (int i = 0; i < weeks; i++)
    {
        totalhours = totalhours + hours[i];
    }

    // tells the computer that the user wants total hours so to print that
    if (output == 'T')
    {
        return totalhours;
    }
    // realizes the only other option is for avg hours, which is calculated here and printed according to main
    else
    {
        float avghours = totalhours / (float) weeks;
        return avghours;
    }
}