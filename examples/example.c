#include "libft.h"
#include <stdio.h>

int main(void)
{
    const char *s = "Hello, Libft!";
    size_t len = ft_strlen(s);
    printf("%s -> %zu\n", s, len);
    ft_putstr_fd("Printed with ft_putstr_fd\n", 1);
    return 0;
}
