#include "main.h"

/**
 * get_len - Get the lenght of a number.
 * @n: type int number.
 * Return: Lenght of a number.
 */
int get_len(int n)
{
	unsigned int n1;
	int lenght = 1;

	if (n < 0)
	{
		lenght++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}
	while (n1 > 9)
	{
		lenght++;
		n1 = n1 / 10;
	}

	return (lenght);
}


/**
* ito_a -> Function that converts int to string.
* @n: int input
*
* Return: string.
*/

char *ito_a(int n)
{
	unsigned int inp;
	int len;
	char *tmp;

	len = get_len(n);
	tmp = malloc(sizeof(char) * (len + 1));
	if (tmp == 0)
		return (NULL);

	*(tmp + len) = EOL;
	if (n < 0)
	{
		inp = n * -1;
		tmp[0] = MINS;
	}
	else
		inp = n;
	len--;

	do {
		*(tmp + len) = (inp % 10) + '0';
		inp /= 10;
		len--;
	}

	while (inp > 0)
		;
		return (tmp);
}


/**
* ato_i -> converts a string to an integer.
* @str: input string.
*
* Return: integer.
*/

int ato_i(char *str)
{
	unsigned int freq = 0, size = 0, oi = 0, pn = 1, m = 1, i;

	while (*(str + freq) != EOL)
	{
		if (size > 0 && (*(str + freq) < '0' || *(str + freq) > '9'))
			break;
		if (*(str + freq) == MINS)
			pn *= -1;
		if ((*(str + freq) >= '0') && (*(str + freq) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		freq++;
	}
	for (i = freq - size; i < freq; i++)
	{
		oi = oi + ((*(str + i) - 48) * m);
		m /= 10;
	}
	return (oi * pn);
}
