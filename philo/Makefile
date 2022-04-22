# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 17:20:19 by nkim              #+#    #+#              #
#    Updated: 2022/04/22 17:21:50 by nkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= philo

CC						= gcc
CFLAGS					= -Wall -Werror -Wextra
AR						= ar rcs
RM						= rm -f
LEAK_FLAGS				= -g3 -fsanitize=address

INCS_DIR				= ./include/
SRCS_DIR				= ./src/
INCS					= -I include

SRC						= main.c util.c
SRCS					= $(addprefix $(SRCS_DIR), $(SRC))
OBJS					= $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	@echo "\033[33m----Compiling lib----"
	$(CC) -o $(NAME) $(OBJS) -I $(INCS_DIR)
	@echo "\n----Philosopher Compiled! 😻----"

all : $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) a.out.dSYM

fclean : clean
	@echo "\n\033[31m----Delete everything 👌!----"
	$(RM) $(NAME) $(NAME).dSYM
	@echo "\n\033[31m----fclean done 👌!----\n"

re : fclean all

test :
	make -C $(LIBFT_DIR)
	$(CC) -g -o $(NAME) $(SRCS) -I $(INCS_DIR)

leak :
	make -C $(LIBFT_DIR)
	$(CC) $(LEAK_FLAGS) -o $(NAME) $(SRCS) -I $(INCS_DIR)

norm :
	norminette $(SRCS) $(INCS_DIR)

PHONY	: all clean fclean re bonus