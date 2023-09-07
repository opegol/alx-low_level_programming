#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings.
 * @s1 : base string
 * @s2 : string to append
 * @n: max number of bytes from s2 to append
 * Return: Pointer to concatenated string in  new memory space
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	int i = 0;
	unsigned int len = 0;
	unsigned int j, k;
	char *s;

	while (s2[i] != '\0')
	{
		i++;
		++len;
	}

	s = malloc(sizeof(*s1) +  n);
	if (s == NULL)
		return (NULL);

	if (s1 == NULL)
		s1[0] = '\0';
	if (s2 == NULL)
		s2[0] = '\0';

	for (j = 0; s1[j] != '\0'; j++)
		s[j] = s1[j];

	k = j;
	for (j = 0; j < n ; j++)
	{
		if (j >= len)
			break;
		s[k + j] = s2[j];
	}

	s[k + j] = '\0';

	return (s);
}
