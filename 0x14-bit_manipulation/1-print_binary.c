#include "main.h"

/**

* print_binary - converts a n number to binary and prints it

* @n: number to convert and print in binary
*/
void print_binary(unsigned long int n)
{
    unsigned long int mask = 1UL << 63;
    int bit_set = 0;

    while (mask > 0)
    {
        if (n & mask)
        {
            putchar('1');
            bit_set = 1;
        }
        else if (bit_set)
        {
            putchar('0');
        }

                mask >>= 1;
    }

    if (!bit_set)
        putchar('0');
}
