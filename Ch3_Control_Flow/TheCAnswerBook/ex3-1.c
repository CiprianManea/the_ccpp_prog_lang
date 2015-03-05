/*
 * Author   : Dennis M. Ritchie
 * Date     : 1-03-2015
 * ----------------------------
 *  Our binary search makes two tests inside the loop, when one would suffice (at the price
 *  of more tests outside). Write a version with only one test inside the loop and measure
 *  the difference in run-time.
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
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
         mid = (low + high) / 2;
    }
    if (x == v[mid])
        return mid;         /* found match */
    else
        return -1;          /* no match */
}
