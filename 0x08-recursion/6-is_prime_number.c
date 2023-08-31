#include "main.h"
/**
 * chk_prime - check if number is prime
 * @n : number
 * @p : check index
 * Return: 1 if n is prime and 0 otherwise
 */
int chk_prime(int n, int p)
{
	if (p == 1)
		return (1);
	else if ((n % p) == 0)
		return (0);
	else
		return (chk_prime(n, p - 1));
}
/**
 * is_prime_number - checks if a number is prime
 * @n : number
 * Return: 1 if number is prime and 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	else
		return (chk_prime(n, n / 2));
}
