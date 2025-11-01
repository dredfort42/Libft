#include "libft.h"

static void write_digit(long n, int fd)
{
	ft_putchar_fd((char)(n + '0'), fd);
}

/**
 * @brief Recursively writes the digits of the number n to the file descriptor fd.
 * @param n The non-negative long integer to write.
 * @param fd The file descriptor to write to.
 */
static void write_number(long n, int fd)
{
	if (n >= 10)
		write_number(n / 10, fd);
	write_digit(n % 10, fd);
}

/**
 * @brief Writes the integer n to the given file descriptor fd.
 * @param n The integer to write.
 * @param fd The file descriptor to write to.
 */
void ft_putnbr_fd(int n, int fd)
{
	long nl = n;

	if (nl < 0)
	{
		ft_putchar_fd('-', fd);
		nl = -nl;
	}
	write_number(nl, fd);
}
