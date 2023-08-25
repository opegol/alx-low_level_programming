#include "main.h"

/**
 * rot13 - function that encodes a string using rot13.
 * @s : given string
 * Return: Pointer to given string
 */
char *rot13(char *s)
{
	int i = 0;
	int j;
	char ch[] =  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char enc[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	while (s[i])
	{
		for (j = 0; j < 52; j++)
		{
			if (s[i] == ch[j])
			{
				s[i] = enc[j];
				break;
			}
		}

		i++;
	}

	return (s);
}
