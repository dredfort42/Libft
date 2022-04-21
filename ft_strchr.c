#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ps;
	int		i;

	ps = (char *)s;
	i = 0;
	while (ps[i])
	{
		if (ps[i] == c)
			return (&ps[i]);
		i++;
	}
	if (c == '\0')
		return (&ps[i]);
	return (0);
}
