#include <stdio.h>
/**
 * main - print some characters
 * Return: Always 0
 */


int main(void)
{
char c, C;

for (c = 'a'; c <= 'z'; c++)
	putchar(c);
for (C = 'A' ; C <= 'Z' ; C++)
	putchar(C);
putchar('\n');

return (0);

}
