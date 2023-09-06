#include "main.h"
#include <stdlib.h>

/**
 * _strdup - function that returns a pointer to a newly
 *		allocated space in memory, which contains a copy of
 *		the string given as a parameter.
 * @str : string to duplicate
 * Return: pointer to duplicated stringy or NULL if memory insufficient
 */
char *_strdup(char *str)
{
	int i = 0;
	int len = 0;
	char *arr;

	while (str[i] != '\0')
	{
		len++;
		i++;
	}

	arr = malloc((sizeof(char) * len) + 1);

	if (arr != NULL)
	{
		for (i = 0; i < len; i++)
			arr[i] = str[i];
	}
	else
		return (NULL);

	return (arr);

}
