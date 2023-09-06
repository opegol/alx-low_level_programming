#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings.
 * @s1 : first string
 * @s2 : second string
 * Return: pointer to concatenated string or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	int i = 0, len1 = 0, len2 = 0;
	char *arr;

	while (s1[i] != '\0')
	{
		len1++;
		i++;
	}

	i = 0;

	while (s2[i] != '\0')
	{
		len2++;
		i++;
	}

	arr = malloc((sizeof(char) * (len1 + len2)) + 1);

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	if (arr != NULL)
	{
		for (i = 0; i < (len1 + len2); i++)
		{
			if (i < len1)
				arr[i] = s1[i];
			else
				arr[i] = s2[i - len1];
		}
		arr[len1 + len2] = '\0';
	}
	else
		return (NULL);

	return (arr);

}
