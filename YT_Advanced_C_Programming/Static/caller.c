/*
 * Date : 14-03-2015
 * -----------------
 *  Caller function to exemplify the static keyword in C
 */

#include <stdio.h>

void print_num(void);

void caller(void) {
    print_num();
    print_num();
    print_num();
}
