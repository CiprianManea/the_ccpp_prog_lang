/*
 * Author   : Ciprian Manea
 * Date     : 28-02-2015
 * ------------------------
 *  Rewrite the function lower, which converts upper case letters
 *  to lower case, with a conditional expression instead of if-else.
 */

#include <stdio.h>

int lower(int letter);

int main()
{
    printf("lower case 'A' is: %c\n", lower('A'));

    return 0;
}

/* lower: converts upper case letters to lower case */
int lower(int letter)
{
    return (letter >= 'A' && letter <= 'Z') ? letter + ('a' - 'A') : letter;
}
