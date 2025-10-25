#include "libft.h"

/**
 * @brief Checks if the given character is an ASCII character.
 * @param c The character to check.
 * @return Returns a non-zero value if the character is an ASCII character,
 *         otherwise returns 0.
 */
int ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
