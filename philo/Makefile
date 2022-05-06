# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 17:20:19 by nkim              #+#    #+#              #
#    Updated: 2022/05/06 16:18:53 by nkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= philo

CC						= gcc
CFLAGS					= -Wall -Werror -Wextra
AR						= ar rcs
RM						= rm -rf
LEAK_FLAGS				= -g3 -fsanitize=thread

INCS_DIR				= ./include
SRCS_DIR				= ./src/
INCS					= -I include

SRC						= main.c init.c philo.c action.c monitor.c util.c error.c
SRCS					= $(addprefix $(SRCS_DIR), $(SRC))
OBJS					= $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	@echo "\033[33m----Compiling lib----"
	$(CC) -o $(NAME) $(OBJS) -I $(INCS_DIR) -lpthread
	@echo "\n----Philosopher Compiled!----"

all : $(NAME)

clean :
	$(RM) $(OBJS) a.out.dSYM

fclean : clean
	@echo "\n\033[31m----Delete everything!----"
	$(RM) $(NAME) $(NAME).dSYM
	@echo "\n\033[31m----fclean done!----\n"

re : fclean all

test :
	$(CC) -g -o $(NAME) $(SRCS) -I $(INCS_DIR)

leak :
	$(CC) $(LEAK_FLAGS) -o $(NAME) $(SRCS) -I $(INCS_DIR) -lpthread

norm :
	norminette $(SRCS) $(INCS_DIR)

PHONY	: all clean fclean re bonus