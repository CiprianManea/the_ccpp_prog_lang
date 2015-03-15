/*
 * Date : 14-03-2015
 * -----------------
 *  Exemplify the static keyword in C
 */

#include <stdio.h>

void caller(void);

static int x = 10;

static void print_num(void) {
    static int y = 0;
    printf("%d\n", y);
    y = y + 1;
}

int main(void) {
    caller();

    return 0;
}
