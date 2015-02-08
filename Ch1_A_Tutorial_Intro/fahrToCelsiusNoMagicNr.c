/*
 * Author   : Dennis M. Ritchie
 * Date     : 08-02-2015
 * ----------------------------
 *  Print Fahrentheit-Celsius table
 * for fahr = 0, 20, ..., 300. Using a for loop.
 * And exemplify the use of #defines raplacing magic numbers.
 */
#include <stdio.h>

#define LOWER   0   /* lower limit of table */
#define UPPER   300 /* upper limit */
#define STEP    20  /* step size */

int main()
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));

    return 0;
}
