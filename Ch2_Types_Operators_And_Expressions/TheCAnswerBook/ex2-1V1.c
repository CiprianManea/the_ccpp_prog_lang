/*
 * Author   : Dennis M. Ritchie
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
    printf("signed char min = %d\n", SCHAR_MIN);
    printf("signed char max = %d\n", SCHAR_MAX);
    printf("unsigned int max = %d\n", UCHAR_MAX);
    printf("signed short min = %d\n", SHRT_MIN);
    printf("signed short max = %d\n", SHRT_MAX);
    printf("unsigned short max = %d\n", USHRT_MAX);
    printf("signed int min = %d\n", INT_MIN);
    printf("signed int max = %d\n", INT_MAX);
    printf("unsigned int max = %d\n", UINT_MAX);
    printf("signed long min = %ld\n", LONG_MIN);
    printf("signed long max = %ld\n", LONG_MAX);
    printf("unsigned long max = %ld\n", ULONG_MAX);

  return 0;
}
