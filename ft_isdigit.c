#include "libft.h"

/**
 * @brief Checks if the given character is a digit.
 * @param c The character to check.
 * @return Returns a non-zero value if the character is a digit,
 *         otherwise returns 0.
 */
int ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
