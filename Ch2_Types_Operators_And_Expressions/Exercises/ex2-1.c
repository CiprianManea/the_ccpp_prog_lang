/*
 * Author   : Ciprian Manea
 * Date     : 22-02-2015
 * ------------------------
 *  Write a program to determine the ranges of char, short, int, 
 * and long variables, both signed and unsigned, by printing appropiate
 * values from standard headers and by direct computation. Harder if
 * you compute them: determine the ranges of the various floating-point types.
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("The number of bits in a byte %d\n", CHAR_BIT);

    printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
    printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
    printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);

    printf("The minimum value of SIGNED SHORT = %d\n", SHRT_MIN);
    printf("The maximum value of SIGNED SHORT = %d\n", SHRT_MAX);
    printf("The maximum value of UNSIGNED SHORT = %d\n", USHRT_MAX);

    printf("The minimum value of SIGNED INT = %d\n", INT_MIN);
    printf("The maximum value of SIGNED INT = %d\n", INT_MAX);
    printf("The maximum value of UNSIGNED INT = %d\n", UINT_MAX);

    printf("The minimum value of SIGNED LONG = %ld\n", LONG_MIN);
    printf("The maximum value of SIGNED LONG = %ld\n", LONG_MAX);
    printf("The maximum value of UNSIGNED LONG = %ld\n", ULONG_MAX);

    printf("The minimum value of FLOAT = %f\n", FLT_MIN);
    printf("The maximum value of FLOAT = %f\n", FLT_MAX);

    printf("The minimum value of DOUBLE = %f\n", DBL_MIN);
    printf("The maximum value of DOUBLE = %f\n", DBL_MAX);

    printf("The minimum value of LONG DOUBLE = %Lf\n", LDBL_MIN);
    printf("The maximum value of LONG DOUBLE = %Lf\n", LDBL_MAX);

   return 0;
}
