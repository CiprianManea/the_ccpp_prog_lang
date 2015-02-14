/*
 * Author   : Ciprian Manea
 * Date     : 14-02-2015
 * ------------------------
 *  Write a program to print a histogram of the frequencies of 
 * different characters in its input.
 */
#include <stdio.h>

#define IN  1               /* inside a word */
#define OUT 0               /* outside a word */
#define MAX_HIST_SIZE   15  /* max length of the histogram */
#define ALPHABET_SIZE   26  /* length of the alphabet */

int main()
{
    int c, i, j, state;
    int charFreq[ALPHABET_SIZE + 1];
    int maxValue, len;

    for (i = 0; i <= ALPHABET_SIZE; i++)
        charFreq[i] = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            state = IN;
            if (c >= 'a' && c <= 'z')
                ++charFreq[c - 'a'];
        } else if (state == IN) {
            state = OUT;
        }
    }

    maxValue = 0;
    for (i = 0; i < ALPHABET_SIZE; ++i)
        if (charFreq[i] > maxValue)
            maxValue = charFreq[i];

    printf("Histogram for word size!\n");
    printf("------------------------\n");
    for (i = 0; i < ALPHABET_SIZE; ++i) {
        printf("%c %4d : ", ('a' + i), charFreq[i]);
        len = charFreq[i] * MAX_HIST_SIZE / maxValue;
        for (j = 0; j < len; ++j)
            putchar('|');
        putchar('\n');
    }

    return 0;
}
