/*
 * Author   : Ciprian Manea
 * Date     : 08-02-2015
 * ----------------------------
 *  Print Fahrentheit-Celsius table
 * for fahr = 300, 280, ..., 0. Using a for loop.
 */
#include <stdio.h>

int main()
{
    int fahr;

    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));

    return 0;
}
