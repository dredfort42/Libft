#include "libft.h"

/**
 * @brief Converts a lowercase letter to uppercase.
 * @param c The character to convert.
 * @return The uppercase equivalent if c is a lowercase letter;
 *         otherwise, returns c unchanged.
 */
int ft_toupper(int c)
{
	if (ft_islower(c))
		c -= 32;
	return (c);
}
