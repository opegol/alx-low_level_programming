#include "main.h"

int len_no_wilds(char *str);
void parse_wild(char **wildstr);
char *post_match(char *str, char *post);
int wildcmp(char *s1, char *s2);

/**
 * len_no_wilds - Returns the string length, ignoring wildcards
 * @s: given string
 * Return: string length
 */
int len_no_wilds(char *s)
{
	int len = 0, i = 0;

	if (*(s + i))
	{
		if (*s != '*')
			len++;
		i++;
		len += len_no_wilds(s + i);
	}
	return (len);
}

/**
 * parse_wild - parses string at a wildcard till
 *		it reaches non-wildcard character.
 * @sw: given string
 */
void parse_wild(char **sw)
{
	if (**sw == '*')
	{
		(*sw)++;
		parse_wild(sw);
	}
}

/**
 * post_match - Checks if a string s matches.
 * @s: The string to be matched.
 * @p: post matched string.
 * Return: If s and p are identical - a pointer to NUL
 * and a pointer to the first unmatched character in post match
 */
char *post_match(char *s, char *p)
{
	int len = len_no_wilds(s) - 1;
	int post_len = len_no_wilds(p) - 1;

	if (*p == '*')
		parse_wild(&p);

	if (*(s + len - post_len) == *p && *p != '\0')
	{
		p++;
		return (post_match(s, p));
	}

	return (p);
}

/**
 * wildcmp - Compares two strings, considering wildcard characters.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared - may contain wildcards.
 * Return: 1 if the strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		parse_wild(&s2);
		s2 = post_match(s1, s2);
	}
	if (*s2 == '\0')
		return (1);
	if (*s1 != *s2)
		return (0);
	return (wildcmp(++s1, ++s2));
}

