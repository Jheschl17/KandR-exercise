#include <stdio.h>

void strcat_ptr(char *s, char *t);

int main()
{
    char str1[] = "hello";
    char str2[] = " world";
    strcat_ptr(str1, str2);
    printf("%s", str1);
}

void strcat_ptr(char *s, char *t)
{
    while (*s != '\0')
        ++s;
    for ( ; *t != '\0'; ++t, ++s)
        *s = *t;
    *s = '\0';
}
