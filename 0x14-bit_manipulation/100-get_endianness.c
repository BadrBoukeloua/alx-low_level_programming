#include "main.h"

/**
 * get_endianness - checks if a machine is little or big endian
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
	unsigned int val = 1;
	char *p_val = (char *) &val;

	return (*p_val);
}

