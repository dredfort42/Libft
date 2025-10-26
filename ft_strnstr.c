#include "libft.h"

/**
 * @brief Locates the first occurrence of the null-terminated string needle
 *        in the string haystack, where not more than len characters are searched.
 * @param haystack Pointer to the string to be searched.
 * @param needle Pointer to the substring to be located.
 * @param len Maximum number of characters to search.
 * @return A pointer to the beginning of the located substring,
 *         or NULL if the substring is not found within the given length.
 */
char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t nlen;

	nlen = ft_strlen(needle);
	if (!nlen)
		return (char *)haystack;
	if (!len)
		return NULL;
	for (i = 0; haystack[i] != '\0' && i < len; ++i)
	{
		if (haystack[i] != needle[0])
			continue;
		/* ensure there is enough room within len for the whole needle */
		if (nlen > len - i)
			continue;
		/* compare needle */
		if (ft_strncmp(haystack + i, needle, nlen) == 0)
			return (char *)(haystack + i);
	}
	return NULL;
}
