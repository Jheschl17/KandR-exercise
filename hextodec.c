#include <stdio.h>
#include <string.h>
#include <ctype.h>

int htoi(char s[]);
int hex_digit_to_decimal_digit(char c);
int readline(char str[]);

int main()
{
    char line[1000];
    readline(line);
    line[strlen(line) - 1] = '\0';
    printf("%d", htoi(line));
}

int htoi(char s[])
{
    int i = 0;
    if (s[1] == 'x' || s[1] == 'X')
        i = 2;

    int ret = 0;
    for (; i < strlen(s); ++i)
        ret = ret * 16 + hex_digit_to_decimal_digit(s[i]);
    return ret;
}

int hex_digit_to_decimal_digit(char c)
{
    if (isdigit(c))
        return c - '0';
    else if (islower(c))
        return 10 + c - 'a';
    else if (isupper(c))
        return 10 + c - 'A';
    else
        return -1;
}

int readline(char str[])
{
    int size = 0;
    int c;
    while ((c = getchar()) != EOF && c != '\n')
        str[size++] = c;
    if (c == '\n')
        str[size++] = '\n';
    str[size++] = '\0';

    return size;
}
