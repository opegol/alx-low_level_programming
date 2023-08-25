#include "main.h"

/**
 * leet - function that encodes a string into 1337.
 * @s : given string
 * Return: Pointer to given string
 */
char *leet(char *s)
{
	int i = 0;
	int j;
	char enc[5] = {52, 51, 48, 55, 49};
	char ch[5] = {'a', 'e', 'o', 't', 'l'};


	while (s[i])
	{
		for (j = 0; j < 5; j++)
		{
			if ((s[i] == ch[j]) || (s[i] == ch[j] - 32))
				s[i] = enc[j];
		}

		i++;
	}

	return (s);
}
