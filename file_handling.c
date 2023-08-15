#include <stdlib.h>
/**
 * move_left -removes leading 0's
 * @a: buffer
 * @size: size of array
 * @num: number of digits in the binary number
 * Return: buffer
 */
char *move_left(char *a, int size, int num)
{
	int i;
	char *por;

	for (i = 0, por = (a + size - num); i < num; i++, por++)
		*(a + i) = *por;
	*(a + num) = '\0';
	return (a);
}

/**
 * get_binary - converts an unsigned int to binary
 * @n: integer
 * Return: pointer to binary
 */

char *get_binary(unsigned int n)
{
	char *por = NULL;
	unsigned int i, num = 0, size = 0;

	if (n == 0)
	{
		por = malloc(2);
		if (por)
		{
			por[0] = '0';
			por[1] = '\0';
		}
		return (por);
	}
	size = sizeof(int) * 8 + 1;
	por = malloc(size);
	if (por)
	{
		for (i = 0; i < size; i++)
		{
			por[i] = '0';
		}
		por[size - 1] = '\0';

		i = size - 2;
		while (n != 0)
		{
			por[i] = n % 2 == 0 ? '0' : '1';
			num++;
			n = n / 2;
			i--;
		}
		num++;
		por = move_left(por, size, num);
	}
	return (por);
}


/**
 * get_char - returns a copied char
 * @c: char to be copied
 * Return: por of copied char
 */
char *get_char(char c)
{
	char *por = NULL;

	por = malloc(2);
	if (por == NULL)
	{
		return (NULL);
	}
	por[0] = c;
	por[1] = '\0';
	return (por);
}

/**
 * get_string - returns a new duplicated string
 * @s: string to be copied
 * Return: Null if string is null, else pointer of copied string
 */
char *get_string(char *s)
{
	char *por = NULL;
	int i, j;

	if (s == NULL)
	{
		por = malloc(7);
		if (por == NULL)
			return (NULL);
		por[0] = '(';
		por[1] = 'n';
		por[2] = 'u';
		por[3] = 'l';
		por[4] = 'l';
		por[5] = ')';
		por[6] = '\0';
		return (por);
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		;
	}
	por = (char *)malloc(i * sizeof(char) + 1);
	if (por == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < i; j++)
	{
		por[j] = s[j];
	}
	por[j] = '\0';
	return (por);
}

/**
 * get_number - put integer into a memory block as string
 * @n: integer
 *
 * Return: pointer to integer string, NULL on error
 */
char *get_number(int n)
{
	int i, len = 0, tmp;
	char *buf = NULL;
	/* find number bytes to allocate */
	tmp = n;
	while (tmp >= 10 || tmp <= -10)
	{
		tmp /= 10;
		len++;
	}
	len++;
	if (n < 0)
		len++;
	buf = malloc(sizeof(char) * (len + 1));
	if (buf)
	{
		buf[len] = '\0';
		if (n < 0)
		{
			buf[0] = '-';
		}
		i = len - 1;
		while (n >= 10 || n <= -10)
		{
			tmp = (n % 10) >= 0 ? n % 10 : -(n % 10);
			buf[i] = tmp + '0';
			i--;
			n /= 10;
		}
		tmp = (n % 10) >= 0 ? n % 10 : -(n % 10);
		buf[i] = tmp + '0';
	}
	return (buf);
}
