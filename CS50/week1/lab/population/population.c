#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    int startsize;
    do
    {
        startsize = get_int("Start size: ");
    }
    while (startsize < 9);

    // TODO: Prompt for end size

    int endsize;
    do
    {
        endsize = get_int("End size: ");
    }
    while (endsize < startsize);

    // TODO: Create years variable

    int years;
    years = 0;

    // TODO: Create population variable

    int population;
    population = 0;
    population = population + startsize;

    // TODO: Calculate number of years until we reach threshold

    if (endsize > startsize)
        do
        {
            population = population + (population / 3) - (population / 4);
            years = years + 1;
        }
        while (population < endsize);

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
