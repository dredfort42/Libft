#include "libft.h"

/**
 * Allocates memory for an array of `count` elements of `size` bytes each
 * and initializes all bytes in the allocated storage to zero.
 * @param count The number of elements to allocate.
 * @param size The size of each element in bytes.
 * @return A pointer to the allocated memory, or NULL if the allocation fails.
 */
void *ft_calloc(size_t count, size_t size)
{
	void *p;

	// prevent multiplication overflow
	// SIZE_MAX = (size_t)-1 (the maximum value representable by size_t).
	// count * size <= SIZE_MAX
	if (size && count > ((size_t)-1) / size)
		return (NULL);
	p = (void *)malloc(count * size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, count * size);
	return (p);
}
