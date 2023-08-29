#include "main.h"
#include <stdio.h>

/**
 * _strstr - locates a substring
 * @haystack : main string from which to get substring
 * @needle : substring
 * Return: pointer to the beginning of the located substring,
 *		or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int j = 0, i = 0, len = 0, c = 0;

	while (needle[len] != '\0')
	{
		len++;
	}
	while (haystack[j] != '\0')
	{
		for (i = 0; i < len; i++)
		{
			if (haystack[j + i] == needle[i])
				c++;
			else
			{
				c = 0;
				break;
			}
		}

		if (len == c)
			return (&haystack[j]);
		j++;

	}

	return (0);
}
