# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zmathews <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 13:31:14 by zmathews          #+#    #+#              #
#    Updated: 2019/10/01 07:45:18 by zmathews         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIBFT_PATH = ./libft/

SRC_PATH = ./srcs/

SRCS = parsing.c \
	  errors.c \
	  store.c \
	  sort.c \
	  print.c \
	  main.c \
	  dash_l.c \
	  more_dash_l.c \

FLAGS = -Wall -Werror -Wextra

INC = -I ./includes/ft_ls.h -I $(LIBFT_PATH)libft.h

SRC = $(addprefix $(SRC_PATH), $(SRCS))

SRC_O = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(SRC_O)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT_PATH)libft.a
	@echo "\033[32m\033[1;32m$(NAME)\033[1;0m\033[32m Created.\033[0m"

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_PATH)/ clean
	@/bin/rm -rf $(SRC_O)
	@echo "\033[31mObject Files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31mRemoved.\033[0m"

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[31m\033[1;31m$(NAME)\033[1;0m\033[31m Removed.\033[0m"

re: fclean all

.PHONY: all fclean clean re