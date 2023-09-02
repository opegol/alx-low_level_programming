#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s : string from which to get substring
 * @accept : string to compare with
 * Return: the number of bytes in the initial segment of s
 *		which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int j = 0, i = 0, c = 0;
	unsigned int spn = 0;

	while (s[i] != '\0')
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			c = spn;
			if (s[i] == accept[j])
			{
				spn++;
				break;
			}
			else
				continue;
		}

		i++;
		if (spn > 0 && (spn - c) == 0)
			break;
	}

	return (spn);
}
