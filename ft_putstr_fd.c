#include "libft.h"

/**
 * @brief Writes the string s to the given file descriptor fd.
 * @param s The string to write.
 * @param fd The file descriptor to write to.
 */
void ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
