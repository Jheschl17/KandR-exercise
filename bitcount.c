#include <stdio.h>

int bitcount(unsigned x);

int main()
{
    printf("%d", bitcount(0b001010010001));
}

int bitcount(unsigned x)
{
    int i;
    for (i = 0; x > 0; i++)
        x &= (x - 1);
    return i;
}
