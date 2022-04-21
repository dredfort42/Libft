#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ps;
	size_t	i;

	ps = (char *)s;
	i = 0;
	while (i < n)
	{
		if (ps[i] == (char)c)
			return ((void *)&ps[i]);
		i++;
	}
	return (0);
}
