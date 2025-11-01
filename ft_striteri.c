#include "libft.h"

/**
 * @brief Applies the function f to each character of the string s,
 *        passing its index as the first argument.
 * @param s The input string to be modified in place.
 * @param f The function to apply to each character and its index.
 */
void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    if (!s || !f)
        return;
    unsigned int i;
    i = 0;
    while (s[i])
    {
        f(i, &s[i]);
        i++;
    }
}