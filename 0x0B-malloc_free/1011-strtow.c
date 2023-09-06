#include <stdlib.h>
#include "main.h"
#include <stdio.h>

/**
 * word_count - finds number of words
 * @str : given string
 * Return: number of words
 */
int word_count(char *str)
{
	int i = 1, word = 0;

	while (str[i] != '\0')
	{
		if (str[i - 1] != ' ' && str[i] == ' ')
		{
			i++;
			word++;
			continue;
		}
		i++;
	}
	return (word);
}
/**
 * strtow - splits a string into words
 * @str : string to split
 * Return: pointer to an array of strings (words) or NULL on failure
 */
char **strtow(char *str)
{
	int i = 0, j, w, k = 0;
	int *n;
	char **s;

	if (str == NULL || (str[0] == '\0'))
		return (NULL);

	w = word_count(str);

	s = malloc(sizeof(char *) * w + 1);

	if (s == NULL)
		return (NULL);

	n = malloc(w * sizeof(int));
/**
 *	if (n == NULL)
 *		return (NULL);
 *
 *	printf("%i\n", n[0]);
 */

/**
 *	while (str[j])
 *	{
 *		if (str[j] == ' ')
 *		{
 *			j++;
 *			continue;
 *		}
 *		while (str[j] && str[j] != ' ')
 *		{
 *			++k;
 *			j++;
 *
 *		printf("k: %i\n", k);
 *		}
 *		*(n + i) = k;
 *		i++, j++, k = 0;
 *		printf("n %i\n i: %i\n", n[i], i);
 *	}
 */

	for (i = 0; i < w; i++)
	{
		s[i] = malloc(sizeof(char) * n[i] + 1);
		if (s[i] == NULL)
			return (NULL);
	/*	printf("n: %i\n", n[i]);*/
	}
	i = 0, j = 0, k = 0;
	while (str[j] != '\0')
	{
		if (str[j] == ' ')
		{
			j++;
			continue;
		}
		while (str[j] && str[j] != ' ')
		{
			s[i][k] = str[j], j++, k++;
		}
		s[i][k] = '\0', i++, j++, k = 0;
	}

	return (s);
}
