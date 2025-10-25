#include "libft.h"

/**
 * @brief Sets the first n bytes of the memory area pointed to by s to zero.
 * @param s Pointer to the memory area to be set to zero.
 * @param n The number of bytes to be set to zero.
 */
void ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
