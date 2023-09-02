#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s : string to look in
 * @c : character to locate
 * Return: pointer to memory area spointer to the first occurrence
 *		of the character c in the string s, or NULL
 *		if the charcter is not found
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return &s[i];
	
		i++;
	}

	return (0);
}
