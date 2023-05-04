#include "main.h"

/**
 * set_bit - sets a bit at a given index to 1
 * @num: pointer to the number to change
 * @idx: index of the bit to set to 1
 *
 * Return: 1 for success, -1 for failure
 */
int set_bit(unsigned long int *num, unsigned int idx)
{
	if (idx > 63)
		return (-1);

	*num = ((1UL << idx) | *num);
	return (1);
}
