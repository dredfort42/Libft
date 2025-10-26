#include "libft.h"

/**
 * @brief Converts the initial portion of the string pointed to by str
 *        to an integer representation.
 * @param str Pointer to the null-terminated string to be converted.
 * @return The converted integer value. If the converted value
 *         is out of range, returns -1 for overflow and 0 for underflow.
 */
int ft_atoi(const char *str)
{
	size_t i = 0;
	int sign = 1;
	unsigned long long res = 0;
	const unsigned long long POS_LIMIT = 2147483647ULL;
	const unsigned long long NEG_LIMIT = 2147483648ULL;

	if (!str)
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (sign == 1 && res > POS_LIMIT)
			return ((int)POS_LIMIT);
		if (sign == -1 && res > NEG_LIMIT)
			return ((int)(-(long long)NEG_LIMIT));
		i++;
	}
	return ((int)(sign * (long long)res));
}
