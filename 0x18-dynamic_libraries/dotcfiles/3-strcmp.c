#include "main.h"

/**
 * _strcmp - compares two strings.
 * @s1 : first string
 * @s2 : string to compare
 *
 * Return: an int greater than 0 if s1 > s2,
 *		0 if equal, and an int < 0 if less than.
 */
int _strcmp(char *s1, char *s2)
{

	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);


	/*for (i = 0; s1[i] && s2[i]; i++)*/
	/*{*/
	/*	if (s1[i] < s2[i])*/
	/*		return (-15);*/
	/*	if (s1[i] > s2[i])*/
	/*		return (15);*/
	/*}*/
	/*return (0);*/

}
