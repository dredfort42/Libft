#include "libft.h"

/**
 * @brief Copies len bytes from memory area src to memory area dst.
 *        The memory areas may overlap; the copy is done in a non-destructive manner.
 * @param dst Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param len The number of bytes to copy.
 * @return A pointer to the destination memory area dst.
 */
void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	const unsigned char *s;
	size_t i;

	if (!dst && !src)
		return (NULL);
	if (len == 0 || dst == src)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d < s)
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dst);
}
