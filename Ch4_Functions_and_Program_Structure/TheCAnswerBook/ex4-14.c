/* Author	: Dennis M. Ritchie 
 * Date		: 19-03-2015
 * ------------------------
 * Define a macro swap(t, x, y) that interchages two arguments
 * of type t. (Block structure will help.)
 */

#include <stdio.h>

#define swap(t, x, y) { t _z;   \
                        _z = y; \
                        y = x;  \
                        x = _z; }

int main()
{
    int x = 12, y = 33;

    swap(int, x, y)
    printf("x = %d; y = %d\n", x, y);

    return 0;
}
