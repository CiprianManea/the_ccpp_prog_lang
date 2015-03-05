/*
 * Author   : Dennis M. Ritchie
 * Date     : 1-03-2015
 * ----------------------------
 *  Implement a function 'shellsort' for sorting an array of integers
 * by using the Shell sort algorithm.
 */

#include <stdio.h>

void shellsort(int v[], int n);

int main()
{
    int i;
    int v[] = {6, 2, 6, 2, 8, 3, 0};

    printf("Array:");
    for (i = 0; i < 7; i++)
        printf(" %d,", v[i]);
    printf("   ; will be sorted by using Shell sort algo.\n");
    shellsort(v, 7);
    printf("Sorted array: ");
    for (i = 0; i < 7; i++)
        printf(" %d,", v[i]);
    printf("\n");

    return 0;
}

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}
