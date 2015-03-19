/* Author	: Ciprian Manea
 * Date		: 19-03-2015
 * ------------------------
 * Define a macro swap(t, x, y) that interchages two arguments
 * of type t. (Block structure will help.)
 */

#include <stdio.h>

#define swap(t, x, y) t = x; \
 					  x = y; \
 					  y = t;

int main()
{
	int t, x = 12, y = 33;

	swap(t, x, y)
	printf("x = %d; y = %d\n", x, y);

	return 0;
}