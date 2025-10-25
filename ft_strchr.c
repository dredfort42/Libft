#include "libft.h"

/**
 * @brief Locates the first occurrence of character c in the string s.
 * @param s Pointer to the string to be searched.
 * @param c The character to locate (converted to char).
 * @return A pointer to the first occurrence of c in s,
 *         or NULL if c is not found.
 */
char *ft_strchr(const char *s, int c)
{
	const unsigned char uc = (unsigned char)c;

	if (!s)
		return (NULL);
	while (*s)
	{
		if ((unsigned char)*s == uc)
			return (char *)s;
		s++;
	}
	if (uc == '\0')
		return (char *)s;
	return (NULL);
}
