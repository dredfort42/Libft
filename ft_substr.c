
#include "libft.h"

// static void *substr(char *sub, const char *s, unsigned int start, size_t len)
// {
// 	size_t i;

// 	i = 0;
// 	while (s[i + start] && i < len)
// 	{
// 		sub[i] = s[i + start];
// 		i++;
// 	}
// 	sub[i] = '\0';
// 	return (sub);
// }

/**
 * Extracts a substring from the string `s`, starting at index `start`
 * and of maximum length `len`. Allocates memory for the substring.
 * @param s The original string.
 * @param start The starting index for the substring.
 * @param len The maximum length of the substring.
 * @return A pointer to the newly allocated substring, or NULL if allocation fails.
 */
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;
	size_t s_len;
	size_t sub_len;
	size_t i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
	{
		sub = (char *)malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	sub_len = s_len - start;
	if (sub_len > len)
		sub_len = len;
	sub = (char *)malloc(sub_len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
