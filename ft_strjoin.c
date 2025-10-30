#include "libft.h"

// static void	ft_join(char *str, const char *s1, const char *s2)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (s1[i])
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 	{
// 		str[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	str[i] = '\0';
// }

/**
 * Joins two strings `s1` and `s2` into a new string by allocating
 * sufficient memory to hold both strings concatenated.
 * @param s1 The first string.
 * @param s2 The second string.
 * @return A pointer to the newly allocated string containing the
 *         concatenation of `s1` and `s2`, or NULL if allocation fails.
 */
char *ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	size_t len1;
	size_t len2;
	size_t total;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > (size_t)-1 - len2 - 1)
		return (NULL);
	total = len1 + len2;
	str = (char *)malloc(total + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(str + len1, s2, len2 + 1); /* copy terminating NUL */
	return (str);
}
