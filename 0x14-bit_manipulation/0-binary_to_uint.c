#include "main.h"

/**
 * binary_to_uint -converts a binary number to an unsigned int.
 * @b: pointing to a string of 0 and 1 chars
 *
 * Return:converted number, or 0
 */

unsigned int binary_to_uint(const char *b)
{
	int i = 0;
	unsigned int dec_val = 0;

	if (!b)
		return (0);

	while (b[i] != '\0')
	{
		if (b[i] == '0' || b[i] == '1')
		{
			dec_val = dec_val << 1;
			dec_val += b[i] - '0';
			i++;
		}
		else
			return (0);
	}

	return (dec_val);
}
