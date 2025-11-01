#include "libft.h"

/**
 * @brief Writes the character c to the given file descriptor fd.
 * @param c The character to write.
 * @param fd The file descriptor to write to.
 */
void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
