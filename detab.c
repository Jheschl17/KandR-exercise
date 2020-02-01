#include <stdio.h>
#include <string.h>

#define TAB_SPACES 4
#define MAX_LENGTH 500

int rd_line(char str[], int max_length);
int calc_detabed_line_size(char str[], int tab_size);
void detab(char str[], int tab_size);
void move_chars(char str[], int index, int amount);
int curr_tab_size(int index, int tab_spaces);

int main()
{
    char line[MAX_LENGTH];
    rd_line(line, MAX_LENGTH);
    char detabed[calc_detabed_line_size(line, TAB_SPACES)];
    strcpy(detabed, line);
    detab(detabed, TAB_SPACES);
    printf("%s", detabed);
}

int rd_line(char str[], int max_length)
{
    int i, c;

    for (i = 0; i < max_length - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
        str[i] = c;
    if (c == '\n')
        str[i] = '\n';
    str[i + 1] = '\0';

    return i;
}

int calc_detabed_line_size(char str[], int tab_size)
{
    int size = 0;
    for (int i = 0; i < strlen(str); ++i)
        if (str[i] == '\t')
            size += tab_size;
        else
            size += 1;

    return size + 1; // + 1 needed because of null byte
}

void detab(char str[], int tab_size)
{
    for (int i = 0; i < strlen(str); ++i)
        if (str[i] == '\t') {
            move_chars(str, i, curr_tab_size(i, tab_size) - 1);
            for (int i2 = 0; i2 < curr_tab_size(i, tab_size); ++i2)
                str[i + i2] = ' ';
        }
}

void move_chars(char str[], int index, int amount)
{
    for (int i = strlen(str); i > index; --i)
        str[i + amount] = str[i];
}

int curr_tab_size(int index, int tab_spaces)
{
    return tab_spaces - (index % tab_spaces);
}
