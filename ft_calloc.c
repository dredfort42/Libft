#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	p = malloc(count * size);
	if (!p)
		return (0);
	ft_memset(p, 0, count * size);
	return (p);
}
