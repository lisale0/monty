#include "monty.h"

/**
 * _strlen - returns string length of input string
 * @s: string to check length of
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * _strncmp - checks if 2 strings are of equal value and length
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to compare
 *
 * Return: difference of first chars of diff value or 0 on success
 */
int _strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

		if (s1[i] == '\0' || s2[i] == '\0')
			return (EXT_SUCCESS)
	}

	return (EXT_SUCCESS);
}
