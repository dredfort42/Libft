# Libft — Reimplementation of common C library functions for 42 school

This repository contains my Libft: a small, hand-written C library that reimplements essential libc functions (strings, memory, conversions) and provides utility functions and linked-list helpers. It is intended as a reusable foundation for 42 school projects and exercises.

## Quick start

Build the static library (requires `make` and `gcc`):

```sh
make        # builds libft.a
make bonus  # build and add bonus (linked-list) functions to libft.a
make clean  # remove object files
make fclean # remove object files and libft.a
make re     # rebuild from scratch
```

To use the library in another project, either copy the source files into your project or link against `libft.a` when compiling:

```sh
gcc -I. -L. -lft your_program.c -o your_program
```

## Examples

Quick example showing how to compile and link a small program against `libft.a`.

Create `example.c`:

```c
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
```

Build options (either link the archive directly or use -lft when libft.a is in the current directory):

```sh
# compile and link with the archive file directly
gcc -I. example.c libft.a -o example

# or use -L. -lft (note: -lft must come after the source/objects)
gcc -I. -L. -lft example.c -o example
```

Run:

```sh
./example
```

## Implemented functions

-   Character classification & conversion
-   Memory management
-   String handling
-   Conversion
    -   `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
    -   `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
    -   `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`
    -   `ft_atoi`

Bonus linked-list helpers (added with `make bonus`):

-   `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Contributing

This repo follows the 42 project rules: all files must compile with `-Wall -Wextra -Werror`, no global variables, and `libft.a` must be created at the repository root using `ar`. If you open PRs, keep changes focused and include tests when possible.

Feel free to open issues or submit PRs for fixes, improvements, or additional functions.
