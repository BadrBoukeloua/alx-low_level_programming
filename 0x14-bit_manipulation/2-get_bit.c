#include "main.h"

/**

* get_bit- returns the value of a bit 

* @n: number 

* @index: index

* Return: value of the bit
*/
int get_bit(unsigned long int n, unsigned int index)
{
    int bit_value;

    if (index > 63)
        return -1;

    bit_value = (n / (1UL << index)) % 2;

    return bit_value;
}
