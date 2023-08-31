#include "main.h"

/**
 * strlen_r - returns the length of a string
 * @s : given string
 * Return: length of string
 */
int strlen_r(char *s)
{
	if (s[0] == '\0')
		return (0);
	else
		return (1 + strlen_r(s + 1));
}
/**
 * chk_palindrome - check if string is a palindrome
 * @s : given string
 * @i : index
 * Return: 1 if string is a palindrome and 0 if not.
 */
int chk_palindrome(char *s, int i)
{
	int len = strlen_r(s) - i - 1;

	if (s[i] == s[len])
	{
		if (i + 1 == len || i == len)
			return (1);

		return (chk_palindrome(s, i + 1));
	}
	return (0);
}
/**
 * is_palindrome - check if a string is a palindrome
 * @s : given string
 * Return: 1 if a string is a palindrome and 0 if not.
 */
int is_palindrome(char *s)
{
	int i = 0;

	if (*s == '\0')
		return (1);

	return (chk_palindrome(s, i));
}
