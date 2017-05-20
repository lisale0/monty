#include "monty.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints string from pointer to string
 * @str: string to print
 *
 * Return: void
 */
void _puts(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
	_putchar('\n');
}

/**
 * write_uint - writes unsigned integers to buffer or stdout in decimal
 * @n: unsigned integer to write
 * Return: number of wrote to buffer
 */
int write_uint(unsigned int n)
{
	unsigned int copy, size;
	int nth, chars_written = 0;

	size = 1;
	copy = n;
	if (n < 10)
	{
		_putchar('0' + n);
		return (1);
	}
	while (copy / 10 != 0)
		copy /= 10, size *= 10;
	while (size > 0)
	{
		nth = n / size;
		_putchar('0' + nth);
		n -= nth * size;
		size /= 10;
		chars_written++;
	}
	return (chars_written);
}
