# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnovikov <dnovikov@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 16:43:26 by dnovikov          #+#    #+#              #
#    Updated: 2025/11/04 17:15:25 by dnovikov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################################################
# libft Makefile
#
# Goals / conventions implemented here:
# - clear, documented variables (CC, CFLAGS, AR, ARFLAGS, RM)
# - separated main and bonus sources/objects
# - portable pattern rule for building .o from .c
# - create static library with `ar rcs` (creates/updates and builds index)
# - `clean` removes all object files, `fclean` removes the library too
# - `bonus` target builds/attaches bonus objects to the archive
############################################################

# Library name
NAME = libft.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

# Archive tool + flags: rcs -> replace/create and write index
AR = ar
ARFLAGS = rcs

# Remove files
RM = rm -f

# -------------------- Sources --------------------
# Core sources (required for the base library)
SRCS_MAIN = \
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_striteri.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c \
	ft_islower_bonus.c ft_isupper_bonus.c ft_digcount_bonus.c ft_isspace_bonus.c

# Optional bonus sources (linked-list helpers)
SRCS_BONUS = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c

# -------------------- Objects --------------------
OBJS_MAIN = $(SRCS_MAIN:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_ALL = $(OBJS_MAIN) $(OBJS_BONUS)

# Default goal
.DEFAULT_GOAL := all

.PHONY: all bonus clean fclean re

# Build the static library from main objects
all: $(NAME)

# Generic rule: compile .c -> .o
# $< = first prerequisite (the .c file)
# $@ = target (the .o file)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create the archive from main objects. Using $@ (target) and $^ (all prerequisites).
$(NAME): $(OBJS_MAIN)
	$(AR) $(ARFLAGS) $@ $^
	@echo "[MAKE] Created $@"

# Bonus: build bonus objects and add them to the archive
# This target leaves $(NAME) present and appends/updates bonus objects in it.
bonus: $(NAME) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS_BONUS)
	@echo "[MAKE] Added bonus objects to $(NAME)"

# Remove generated object files
clean:
	$(RM) $(OBJS_ALL)
	@echo "[MAKE] Cleaned object files"

# Remove everything including the static library
fclean: clean
	$(RM) $(NAME)
	@echo "[MAKE] Removed $(NAME)"

# Rebuild from scratch
re: fclean all

############################################################
