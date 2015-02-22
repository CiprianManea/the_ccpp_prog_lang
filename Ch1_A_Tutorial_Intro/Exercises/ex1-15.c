/*
 * Author   : Ciprian Manea
 * Date     : 15-02-2015
 * ----------------------------
 *  Print Fahrentheit-Celsius table
 * for fahr = 0, 20, ..., 300
 */
#include <stdio.h>

int fahrToCelsius(int fahr);

int main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = fahrToCelsius(fahr);
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

int fahrToCelsius(int fahr)
{ 
    return (5 * (fahr - 32) / 9);
}
