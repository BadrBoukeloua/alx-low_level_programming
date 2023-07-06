#include "main.h"

/**

* print_binary - converts a n number to binary and prints it

* @n: number to convert and print in binary
*/
void print_binary(unsigned long int n)
{
    int index;

    unsigned long int mask = sizeof(n) * 8;

    while (!(n & mask) && mask)
        mask >>= 1;

    while (mask)
    {
        _putchar((n & mask) ? '1' : '0');
        mask >>= 1;
    }

    if (!n)
        _putchar('0');
}
