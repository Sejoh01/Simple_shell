#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "shell.h"
#include "main.h"
/**
 * _strcpy - copies a string to anther memory adress
 * @src: pointer to the source string
 * @dest: pointer to the dest address
 *
 * Return: pointer to the dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i] = '\n';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: correct response
 */
int _strcmp(char *s1, char *s2)
{
	int response = 0;

	do {
		response = *s1 - *s2;
		if (*s1 == 0 || *s2 == 0)
			break;
		s1++;
		s2++;
	} while (response == 0);

	return (response);
}

/**
 * _strcmp_n - compares n bytes of two strings
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to comp
 *
 * Return: correct response
 */
int _strcmp_n(char *s1, char *s2, int n)
{
	int i = 0, response = *s1 - *s2;

	while (i <= n)
	{
		response = *(s1++) - *(s2++);
		if (response != 0)
			break;
		i++;
	}

	return (response);
}


/**
 * _atoi - turn a str into an int
 * @s: string to eval
 * Return: n the value of the first number in the st0ring
 */
int _atoi(char *s)
{
	int n, tmp, len, mul = 1;

	n = 0;
	tmp = 0;

	len = _strlen(s);
	len--;
	while (len >= 0)
	{
		tmp = n;
		n = n + (s[len] - '0') * mul;
		if (n < tmp || n > INT_MAX)
			return (-1);
		len--;
		mul *= 10;
	}
	return (n);
}
