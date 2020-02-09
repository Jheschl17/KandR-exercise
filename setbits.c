#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    unsigned x = 261234;
    unsigned y = 7645;
    int n = 4;
    int p = 6;
    printf("%u\n", setbits(x, p, n, y));
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned mask = ~(~0U << (unsigned) n) << (unsigned) (p - n);
    unsigned x_filtered = x & ~mask;
    unsigned y_extracted = (y & ~(~0U << (unsigned) n)) << (unsigned) (p - n);
    return x_filtered | y_extracted;
}
