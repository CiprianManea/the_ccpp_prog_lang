/*
 * Author   : Ciprian Manea
 * Date     : 06-02-2015
 * ----------------------------
 *  Print Celsius-Fahrentheit table
 * for fahr = 0, 20, ..., 300; floatin-point version.
 * In addition, prints a header above the table.
 */
#include <stdio.h>

int main()
{
    float celsius, fahr;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("Celsius | Fahrenheit\n");
    printf("--------------------\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32;
        printf("%5.0f %11.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
