# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpisani <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 14:25:19 by mpisani           #+#    #+#              #
#    Updated: 2025/01/20 14:25:22 by mpisani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Cartella dove risiede il tuo ft_printf e il suo Makefile
PRINTF_DIR = ../

NAME = test_printf
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main_test.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n--- [ Compiling ft_printf project ] ---"
	$(MAKE) -C $(PRINTF_DIR) # lancia il Makefile del tuo ft_printf
	@echo "\n--- [ Building test executable ] ---"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(PRINTF_DIR) -lftprintf
	@echo "\n--- [ Done! Use \"make run\" to execute ] ---"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "Test object files removed!"

fclean: clean
	rm -f $(NAME)
	@echo "Test binary removed!"

re: fclean all

run: $(NAME)
	@echo "\n--- [ Running tests ] ---\n"
	./$(NAME)

.PHONY: all clean fclean re run
