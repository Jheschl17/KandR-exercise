#include <stdio.h>

int any(char s1[], char s2[]);
int contains(char s[], int c);

int main()
{
    printf("%i\n", any("hello world", "xzzyzy"));
    printf("%i\n", any("hello world", "l"));
    printf("%i\n", any("hello world", "abcow"));
}

int any(char s1[], char s2[])
{
    for (int i = 0; s1[i] != '\0'; i++)
        if (contains(s2, s1[i]))
            return i;
    return -1;
}

int contains(char s[], int c)
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            return 1;
    return 0;
}
