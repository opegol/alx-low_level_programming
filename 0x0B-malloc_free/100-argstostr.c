#include <stdlib.h>
#include "main.h"

/**
 * slen - finds length of string
 * @str : given string
 * Return: length of string
 */
int slen(char *str)
{
	int i = 0, len = 0;

	while (str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}
/**
 * argstostr - concatenates all the arguments of your program.
 * @ac : count of program arguments
 * @av : array of program arguments
 * Return: pointer to a new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	int i, tot_len = 0, k = 0, j = 0;
	char *s;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
		tot_len += slen(av[i]);
	i = 0;

	s = malloc(sizeof(char) * tot_len + ac);

	if (s == NULL)
		return (NULL);

	for (j = 0; j < ac; j++)
	{
		while (av[j][k])
		{
			s[i] = av[j][k];
			i++;
			k++;
		}
		s[i] = '\n';
		i++;
		k = 0;
	}

	return (s);
}
