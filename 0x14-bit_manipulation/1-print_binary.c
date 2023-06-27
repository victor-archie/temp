#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: num of prented
 * Return: void
 */


void print_binary(unsigned long int n)
{
	unsigned long int i;
	unsigned int flag = 1<<(sizeof(int) * 8 - 1);

	for (i = 0; i < (sizeof(unsigned long int) * 8); i++)
	{
		(n & flag) ? _putchar('1') : _putchar('0');
		n = n << 1;
	}
}
