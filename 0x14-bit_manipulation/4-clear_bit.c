#include "main.h"

/**
 * clear_bit - sets the value of a given bit to 0
 * @num_ptr: pointer to the number to change
 * @bit_index: index of the bit to clear
 *
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *num_ptr, unsigned int bit_index)
{
	if (bit_index > 63)
		return (-1);

	*num_ptr = (~(1UL << bit_index) & *num_ptr);
	return (1);
}

