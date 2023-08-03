#include "main.h"

/**

* clear_bit_to_zero - sets the value of a given bit to 0

* @decimal: the number to change

* @index: index of the bit 

* Return: 1 for success, -1 for failure
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
    if (index > 63)
        return -1;

    *n &= ~(1UL << index);
    return 1;
}
