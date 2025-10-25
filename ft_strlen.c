#include "libft.h"

/**
 * @brief Calculates the length of a string.
 * @param s The string whose length is to be calculated.
 * @return The length of the string.
 */
size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
