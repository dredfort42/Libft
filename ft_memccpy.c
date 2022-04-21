#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*pdst;
	char	*psrc;
	size_t	i;

	pdst = (char *)dst;
	psrc = (char *)src;
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		if (pdst[i] == (char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
