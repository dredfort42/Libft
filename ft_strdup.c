#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (0);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
