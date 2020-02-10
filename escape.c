#include <stdio.h>

void escape(char s1[], char s2[]);
void unescape(char s1[], char s2[]);

int main()
{
    char s1[] = "asdf\n\nbasd\tasv";
    char s2[100];
    escape(s1, s2);
    printf("%s\n", s2);

    char s3[] = "fabse\\t\\nacde\\asdbe\\";
    char s4[100];
    unescape(s3, s4);
    printf("%s\n", s4);

    return 1;
}

void escape(char s1[], char s2[])
{
    int j = 0;
    for (int i = 0; s1[i] != '\0'; ++i){
        switch (s1[i]) {
            case '\n':
                s2[j] = '\\';
                s2[++j] = 'n';
                break;

            case '\t':
                s2[j] = '\\';
                s2[++j] = 't';
                break;

            default:
                s2[j] = s1[i];
        }
        j++;
    }
    s2[++j] = '\0';
}

void unescape(char s1[], char s2[])
{
    int j = 0;
    for (int i = 0; s1[i] != '\0'; ++i) {
        if (s1[i] == '\\') {
            switch (s1[++i]) {
                case 't':
                    s2[j] = '\t';
                    break;

                case 'n':
                    s2[j] = '\n';
                    break;

                default:
                    s2[j] = '\\';
                    i--;
            }
        } else {
            s2[j] = s1[i];
        }
        j++;
    }
    s2[++j] = '\0';
}
