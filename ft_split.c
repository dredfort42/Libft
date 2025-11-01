#include "libft.h"

/**
 * @brief Counts the number of words in the string s separated by the delimiter c.
 * @param s The input string.
 * @param c The delimiter character.
 * @return The number of words found in the string.
 */
static size_t count_words(const char *s, char c)
{
	size_t count = 0;

	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

/**
 * @brief Calculates the length of the next word in the string s up to the delimiter c.
 * @param s The input string.
 * @param c The delimiter character.
 * @return The length of the next word.
 */
static size_t next_word_len(const char *s, char c)
{
	size_t len = 0;

	while (s[len] && s[len] != c)
		len++;
	return (len);
}

/**
 * @brief Frees the allocated memory for the array of words.
 * @param arr The array of strings to be freed.
 * @param filled The number of words that have been allocated in the array.
 */
static void free_words(char **arr, size_t filled)
{
	size_t i;

	if (!arr)
		return;
	for (i = 0; i < filled; ++i)
		free(arr[i]);
	free(arr);
}

/**
 * @brief Splits the string s into an array of strings using the delimiter c.
 * @param s The input string to be split.
 * @param c The delimiter character.
 * @return A NULL-terminated array of strings resulting from the split.
 *         Returns NULL if memory allocation fails or if s is NULL.
 */
char **ft_split(char const *s, char c)
{
	char **arr;
	size_t words;
	size_t i;
	size_t len;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arr = malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		len = next_word_len(s, c);
		arr[i] = (char *)malloc(len + 1);
		if (!arr[i])
		{
			free_words(arr, i);
			return (NULL);
		}
		ft_strlcpy(arr[i], s, len + 1);
		s += len;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
