#include "main.h"
/**
 * nat_sqrt - find natural square root
 * @n : number
 * @r : guess root
 * Return: square root
 */
int nat_sqrt(int n, int r)
{
	if ((r < 1) || (r * r > n))
		return (-1);
	else if ((n / r) == r && (n % r) == 0)
		return (r);
	else
		return (nat_sqrt(n, r + 1));
}
/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n : number
 * Return: natural square root of @n
 */
int _sqrt_recursion(int n)
{
	if (n == 1)
		return (1);
	else if (n == 0)
		return (0);
	else
		return (nat_sqrt(n, 2));
}
