#include "main.h"

/**

count_flip_bits - counts the number of bits to change

to get from one number to another

@n: first number

@m: second number

Return: number of bits to change
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned long int ex = n ^ m;
    unsigned int c = 0;

    while (ex > 0)
    {
        if (ex & 1)
            c++;
        ex >>= 1;
    }

    return c;
}
