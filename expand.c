#include <stdio.h>
#include <string.h>
#include <ctype.h>

void expand(char s1[], char s2[]);
void expand_part(char from, char to, char out[]);

int main()
{
    char s1[] = "----asdfa-z2314a--1-5-8a--";
    char s2[100];
    expand(s1, s2);
    printf("%s\n", s2);
}

void expand(char s1[], char s2[])
{
    int j = 0;
    for (int i = 0; i < strlen(s1); i++, j++) {
        if (
            s1[i] == '-'
            &&
            (
                (islower(s1[i - 1]) && islower(s1[i + 1]))
                ||
                (isupper(s1[i - 1]) && isupper(s1[i + 1]))
                ||
                (isdigit(s1[i - 1]) && isdigit(s1[i + 1]))
            )
        ) {
            char part[30];
            expand_part(s1[i - 1] + 1, s1[i + 1], part);
            j += (int) strlen(part) - 1;
            i += 1;
            strcat(s2, part);
        } else
            s2[j] = s1[i];
    }
    s2[j] = '\0';
}

void expand_part(char from, char to, char out[])
{
    int i;
    for (i = from; i <= to; ++i)
        out[i - from] = (char) i;
    out[i - from] = '\0';
}
