#include "libft.h"

/**
 * @brief Checks if the given character is printable.
 * @param c The character to check.
 * @return Returns a non-zero value if the character is printable,
 *         otherwise returns 0.
 */
int ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
