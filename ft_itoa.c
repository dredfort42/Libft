#include "libft.h"

static int is_negative(int n)
{
	return (n < 0);
}

/**
 * @brief Counts the number of digits in a non-negative long integer.
 * @param value The non-negative long integer.
 * @return The number of digits in the integer.
 */
static int count_digits(long value)
{
	int digits = 1;
	while (value >= 10)
	{
		value /= 10;
		digits++;
	}
	return (digits);
}

/**
 * @brief Converts an integer to its string representation.
 * @param n The integer to convert.
 * @return A pointer to the newly allocated string representing the integer.
 *         Returns NULL if memory allocation fails.
 */
char *ft_itoa(int n)
{
	long value = n;
	int neg = is_negative(n);
	int digits;
	int len;
	char *str;

	if (neg)
		value = -value;
	digits = count_digits(value);
	len = digits + neg + 1; /* +1 for NUL */
	str = (char *)malloc((size_t)len);
	if (!str)
		return (NULL);
	str[len - 1] = '\0';
	/* fill digits from the end */
	while (digits--)
	{
		str[neg + digits] = (char)('0' + (value % 10));
		value /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
