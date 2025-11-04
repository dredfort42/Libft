#include "libft.h"

/**
 * @brief Counts the number of digits in a non-negative long integer.
 * @param n The integer to analyze.
 * @return The number of digits in the integer.
 */
int ft_digcount(int n)
{
	int digits;

	digits = 0;
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}