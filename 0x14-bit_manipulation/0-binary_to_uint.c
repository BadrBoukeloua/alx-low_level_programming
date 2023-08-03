#include "main.h"

/**

* binary_to_unit - converts a binary number to decimal

* @b: string containing the binary number

* Return: the converted decimal number
*/
unsigned int binary_to_uint(const char *b)
{
    int index;
    unsigned int decimal = 0;

    if (!b)
        return 0;

    for (index = 0; b[index]; index++)
    {
        if (b[index] != '0' && b[index] != '1')
            return 0;
        decimal = decimal * 2 + (b[index] - '0');
    }

    return decimal;
}
