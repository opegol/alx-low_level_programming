/* 1-isdigit.c */

#include "main.h"

/**
 * _isdigit  - checks for a digit (0 through 9)
 * @c : digit to be checked
 *
 * Return: 1 if c is a digit and 0 otherwise
 */

int _isdigit(int c)
{
	if ((c >= 0 && c <= 9) || ((char)c >= 48 && (char)c <= 58))
		return (1);
	else
		return (0);

}
