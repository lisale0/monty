#include "monty.h"

/**
 * are_digits - checks if every char in a string is a digit
 * @num: number to check if all chars are digits
 *
 * Return: TRUE or FALSE
 */
int are_digits(char *num)
{
	int i;

	for (i = 0; num[i] != '\0'; i++)
		if (isdigit(num[i]) == FALSE)
			return (FALSE);

	return (TRUE);
}

/**
 * itos - integer to string
 * @str: char array
 * @n: number
 *
 * Return: char array
 */
char *itos(char str[], long int n)
{
	int i, temp, div, length, last;

	last = n % 10;
	i = 0;
	if (last < 0)
	{
		last *= -1;
		str[i] = '-';
		i++;
	}
	n = (n / 10);
	if (n < 0)
	{
		n *= -1;
	}

	length = 0;
	div = 1;
	temp = n;

	while (temp > 0)
	{
		length += 1;
		div *= 10;
		temp = temp / 10;
	}

	div = div / 10;
	while (div >= 1)
	{
		str[i] = ((n / div) + '0');
		n = n % div;
		div /= 10;
		i++;
	}
	str[i] = last + '0';
	return (str);
}
/**
 * num_len - getting the length of a number
 * @num: the number
 *
 * Return: int
 */
int num_len(int num)
{
	int n, len;

	n = num;
	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
