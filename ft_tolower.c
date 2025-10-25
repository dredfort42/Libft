#include "libft.h"

/**
 * @brief Converts an uppercase letter to lowercase.
 * @param c The character to convert.
 * @return The lowercase equivalent if c is an uppercase letter;
 *         otherwise, returns c unchanged.
 */
int ft_tolower(int c)
{
	if (ft_isupper(c))
		c += 32;
	return (c);
}
