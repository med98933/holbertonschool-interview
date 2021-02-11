#include "palindrome.h"

/**
 * is_palindrome -  checks if an unsigned integer is a palindrome
 * @n: input integer
 * Return: 1 if n is palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	int num = 0;
	unsigned long i = 0;
	unsigned long total = n;

	while (n != 0)
	{
		num = n % 10;
		i = (i * 10) + num;
		n /= 10;
	}
	if (i == total)
	{
		return (1);
	}
	return (0);
}