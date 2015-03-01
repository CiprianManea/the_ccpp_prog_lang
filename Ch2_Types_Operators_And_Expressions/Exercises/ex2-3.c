/*
 * Author   : Ciprian Manea
 * Date     : 25-02-2015
 * ------------------------
 *  Write the function htoi(s), which converts a string of hexa-decimal digits
 * (including an optional 0x or 0X) into its equivalent integer value. The 
 * allowable digits are 0 through 9, a through f, and A through F.
 */
#include <stdio.h>
#include <ctype.h>

int main()
{
    int i, c, n;
    char s[] = "0x1234FE";

    n = i = 0;
    if (s != NULL && s[i] == '0')
        i += 2;
    while (s[i] != '\0') {
        if (isdigit(s[i])) {
            n = 16 * n + (s[i] - '0');
        } else if (isalpha(s[i])) {
            c = toupper(c);
            n = 16 * n + (s[i] - 'A' + 10);
        }
        ++i;
    }
    printf("Decimal value for %s = %d\n", s, n);

    return 0;
}
