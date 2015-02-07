/*
 * Author   : Ciprian Manea
 * Date     : 06-02-2015
 * ----------------------------
 *  Print Fahrentheit-Celsius table
 * for fahr = 0, 20, ..., 300; floatin-point version.
 * In addition, prints a header above the table.
 */
#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("Fahr | Celsius\n");
    printf("--------------\n");
    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f %8.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
