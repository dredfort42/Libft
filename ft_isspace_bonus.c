#include "libft.h"

/**
 * @brief Checks if a character is a space character.
 * @param ch The character to check.
 * @return 1 if the character is a whitespace character, 0 otherwise.
 */
int ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}
