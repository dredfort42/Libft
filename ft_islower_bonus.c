#include "libft.h"

/**
 * @brief Checks if the given character is a lowercase letter.
 * @param c The character to check.
 * @return Returns a non-zero value if the character is a lowercase letter,
 *         otherwise returns 0.
 */
int ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
