#include "main.h"

/**
 * _strpbrk - locates the first occurrence in the string s
 *		of any of the bytes in the string accept
 * @s : main string from which to get sub
 * @accept : string set to compare with
 * Return: pointer to the byte in s that matches one of
 *	the bytes in accept, or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	int j = 0, i = 0;

	while (s[i] != '\0')
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				return (&s[i]);
			}
			else
				continue;
		}

		i++;

	}

	return (0);
}
