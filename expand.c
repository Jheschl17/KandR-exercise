#include <stdio.h>
#include <string.h>
#include <ctype.h>

void expand(char s1[], char s2[]);
void expand_part(char from, char to, char out[]);

int main()
{

}

void expand(char s1[], char s2[])
{
    int j = 0;
    for (int i = 0; i < strlen(s1); i++, j++) {
        if (isupper(s1[i]))
            ;
        else if (islower(s1[i]))
            ;
        else if (isdigit(s1[i]))
            ;
        else
            s2[j] = s1[i];
    }
}

void expand_part(char part[], char out[])
{

}
