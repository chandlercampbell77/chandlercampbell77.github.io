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
    while (height < 1 || height > 8);

    // prints height of 1
    if (height == 1)
    {
        printf("#");
        printf("\n");
    }

    // prints height of 2
    if (height == 2)
    {
        printf(" #");
        printf("\n");
        printf("##");
        printf("\n");

    }

    // prints height of 3
    if (height == 3)
    {
        printf("  #");
        printf("\n");
        printf(" ##");
        printf("\n");
        printf("###");
        printf("\n");
    }

    // prints height of 4
    if (height == 4)
    {
        printf("   #");
        printf("\n");
        printf("  ##");
        printf("\n");
        printf(" ###");
        printf("\n");
        printf("####");
        printf("\n");
    }

    // prints height of 5
    if (height == 5)
    {
        printf("    #");
        printf("\n");
        printf("   ##");
        printf("\n");
        printf("  ###");
        printf("\n");
        printf(" ####");
        printf("\n");
        printf("#####");
        printf("\n");
    }

    // prints height of 6
    if (height == 6)
    {
        printf("     #");
        printf("\n");
        printf("    ##");
        printf("\n");
        printf("   ###");
        printf("\n");
        printf("  ####");
        printf("\n");
        printf(" #####");
        printf("\n");
        printf("######");
        printf("\n");
    }

    // prints height of 7
    if (height == 7)
    {
        printf("      #");
        printf("\n");
        printf("     ##");
        printf("\n");
        printf("    ###");
        printf("\n");
        printf("   ####");
        printf("\n");
        printf("  #####");
        printf("\n");
        printf(" ######");
        printf("\n");
        printf("#######");
        printf("\n");
    }

    // prints height of 8
    if (height == 8)
    {
        printf("       #");
        printf("\n");
        printf("      ##");
        printf("\n");
        printf("     ###");
        printf("\n");
        printf("    ####");
        printf("\n");
        printf("   #####");
        printf("\n");
        printf("  ######");
        printf("\n");
        printf(" #######");
        printf("\n");
        printf("########");
        printf("\n");
    }
}