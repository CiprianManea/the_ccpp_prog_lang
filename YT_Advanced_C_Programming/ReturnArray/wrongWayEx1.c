/*
 * Date : 15-03-2015
 * ----------------
 *  Showing the wrong way of returning arrays.
 *      - You can not assign something to an array after you defined it.
 */

#include <stdio.h>

char *return_char_arr()
{
    char char_arr[] = "This is a char array";
    return char_arr;
}

int main(void)
{
    char a[10];

    a = return_char_arr();
    printf("%s\n", a);

    return 0;
}
