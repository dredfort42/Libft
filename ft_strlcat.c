#include "libft.h"

/**
 * @brief Appends the string src to the end of dst.
 *        It will append at most dstsize - strlen(dst) - 1 characters.
 *        It will then NUL-terminate, unless dstsize is 0 or
 *        the original dst string was longer than dstsize.
 * @param dst Pointer to the destination string.
 * @param src Pointer to the source string.
 * @param dstsize The total size of the destination buffer.
 * @return The total length of the string it tried to create,
 *         that is the initial length of dst plus the length of src.
 */
size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dlen;
	size_t slen;
	size_t copy;

	slen = ft_strlen(src);
	/* find length of dst but no further than dstsize */
	dlen = 0;
	while (dlen < dstsize && dst[dlen])
		dlen++;
	/* if no space to append, return dstsize + strlen(src) */
	if (dlen == dstsize)
		return (dstsize + slen);
	/* number of bytes we can copy from src (leave room for NUL) */
	if (dstsize - dlen - 1 > 0)
		copy = dstsize - dlen - 1;
	else
		copy = 0;
	/* copy */
	if (copy)
	{
		size_t i;

		i = 0;
		while (i < copy && src[i])
		{
			dst[dlen + i] = src[i];
			i++;
		}
		dst[dlen + i] = '\0';
	}
	return (dlen + slen);
}
