# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpisani <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 11:02:09 by mpisani           #+#    #+#              #
#    Updated: 2025/01/19 17:10:55 by mpisani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_print_char.c ft_print_hex.c ft_print_numbers.c ft_print_percent.c ft_print_ptr.c \
ft_print_string.c ft_printf.c ft_sort_printf.c

OBJS = $(SRCS:.c=.o)

AR = ar
ARFLAGS = rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)

	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "$(NAME) created!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

	@echo "File .c removed, not the .a"

fclean: clean
	$(RM) $(NAME)
	@echo "All cleaned!"

re: fclean all

.PHONY: all clean fclean re
