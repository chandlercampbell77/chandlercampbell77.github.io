// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float foodcost = get_float("Bill before tax and tip: ");
    float taxpercent = get_float("Sale Tax Percent: ");
    float tippercent = get_int("Tip percent: ");


    float taxdecimal = taxpercent / 100.0;

    float tipdecimal = tippercent / 100.0;

    float taxamount = foodcost * taxdecimal;
    float foodwithtax = foodcost + taxamount;
    float tipamount = foodwithtax * tipdecimal;
    float total = tipamount + foodwithtax;
    float half = total / 2;

    printf("You will owe $%.2f each!\n", half);
}