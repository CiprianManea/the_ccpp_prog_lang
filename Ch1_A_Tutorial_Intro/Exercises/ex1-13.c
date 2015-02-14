/*
 * Author   : Ciprian Manea
 * Date     : 14-02-2015
 * ------------------------
 *  Write a program to print a histogram of the lengths of words in
 * its input. It is easy to draw the histogram with the bars horizontal;
 * a vertical orientation is more challenging.
 */
#include <stdio.h>

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word */
#define MAX_HIST_SIZE   15  /* maximum size for the histogram */
#define MAX_WORD_SIZE   11  /* maximum size for a word */

int main()
{
    int c, state, lettersInWord, i, j;
    int wordOverflow, histOverflow;
    int nWords[MAX_WORD_SIZE + 1];

    for (i = 0; i <= MAX_WORD_SIZE; i++)
        nWords[i] = 0;
    lettersInWord = 0;
    wordOverflow = histOverflow = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            state = IN;
            lettersInWord++;
        } else if (state == IN) {
            state = OUT;
            if (lettersInWord > MAX_WORD_SIZE) {
                ++wordOverflow;
                lettersInWord = MAX_WORD_SIZE;
            }
            ++nWords[lettersInWord];
            lettersInWord = 0;
        }
    }

    printf("Histogram for word size!\n");
    printf("------------------------\n");
    for (i = 1; i <= MAX_WORD_SIZE; i++) {
        if (nWords[i] > MAX_HIST_SIZE) {
            histOverflow = 1;
            nWords[i] = MAX_HIST_SIZE;    
        }

        printf("[%2d] ", i);
        for (j = 0; j < nWords[i]; j++) {
            printf("|");
        }
        if (histOverflow)
            printf("+");
        printf("\n");

        histOverflow = 0;
    }

    printf("How many times Word Overflow happned? %d\n", wordOverflow);

    return 0;
}
