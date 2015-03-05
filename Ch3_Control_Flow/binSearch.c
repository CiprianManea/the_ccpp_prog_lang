/*
 * Author   : Dennis M. Ritchie
 * Date     : 1-03-2015
 * ----------------------------
 *  This program will show the implementation of a binary search.
 * ----------------------------
 *  Binary search first compares the input value x to the middle element of the array v.
 * If x is less that the middle value, searching focuses on the lower half of the table,
 * otherwise on the upper half. In either case, the next step is to compare x to the 
 * midle element of the selected half. This process of dividing the range in two conti-
 * nues until the value is found of the range is empty.
 */

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int v[] = {12, 2, 6, 10, 55, 4, 19};
    int x = 4;

    printf("Is %d in v[] ? %s", x, (binsearch(x, v, 7) >= 0) ? "yes" : "no");

    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else        /* found match */
            return mid;
    }
    return -1;      /* no match */
}
