#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Asking user for name
    string name = get_string("What's your name? ");
    // Responding to user
    printf("hello, %s\n", name);
}