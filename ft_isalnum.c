#include "libft.h"

/**
 * @brief Checks if the given character is alphanumeric.
 * @param c The character to check.
 * @return Returns a non-zero value if the character is alphanumeric,
 *         otherwise returns 0.
 */
int ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
