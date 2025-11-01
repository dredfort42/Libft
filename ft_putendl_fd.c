#include "libft.h"

/**
 * @brief Writes the string s followed by a newline to the given file descriptor fd.
 * @param s The string to write.
 * @param fd The file descriptor to write to.
 */
void ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		write(fd, "\n", 1);
	}
}
