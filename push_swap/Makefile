# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 17:20:19 by nkim              #+#    #+#              #
#    Updated: 2022/04/13 19:51:36 by nkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= push_swap

CC						= gcc
CFLAGS					= -Wall -Werror -Wextra
AR						= ar rcs
RM						= rm -f
LEAK_FLAGS				= -g3 -fsanitize=address

LIBFT_DIR				= ./libft/
LIBFT_FLAGS				= -L ./$(LIBFT_DIR) -lft
LIBFT_FILE				= $(LIBFT_DIR)libft.a

INCS_DIR				= ./include/
SRCS_DIR				= ./src/
INCS					= -I include

SORT_DIR_SRC			= sort/
SORT_SRC				= pivot.c sort_a_to_b.c sort_b_to_a.c \
						sort_some.c validate.c

STACK_DIR_SRC			= stack/
STACK_SRC				= stack.c validate.c

OPERATOR_DIR_SRC		= operator/
OPERATOR_SRC			= operator.c swap.c push.c rotate.c reverse_rotate.c

UTILS_DIR_SRC			= utils/
UTILS_SRC				= array_to_int.c error.c

TEST_DIR_SRC			= __test__/
TEST_SRC				= test.c print.c

SRC						= main.c \
						$(addprefix $(SORT_DIR_SRC), $(SORT_SRC)) \
						$(addprefix $(STACK_DIR_SRC), $(STACK_SRC)) \
						$(addprefix $(OPERATOR_DIR_SRC), $(OPERATOR_SRC)) \
						$(addprefix $(UTILS_DIR_SRC), $(UTILS_SRC)) \
						$(addprefix $(TEST_DIR_SRC), $(TEST_SRC))
SRCS					= $(addprefix $(SRCS_DIR), $(SRC))
OBJS					= $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	@echo "\033[33m----Compiling lib----"
	make -C $(LIBFT_DIR)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) -I $(INCS_DIR)
	@echo "\n----Push_swap Compiled! 😻----"

all : $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) a.out.dSYM

fclean : clean
	@echo "\n\033[31m----Delete everything 👌!----"
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(NAME).dSYM
	@echo "\n\033[31m----fclean done 👌!----\n"

re : fclean all

test :
	make -C $(LIBFT_DIR)
	$(CC) -g -o $(NAME) $(SRCS) $(LIBFT_FLAGS) -I $(INCS_DIR)

leak :
	make -C $(LIBFT_DIR)
	$(CC) $(LEAK_FLAGS) -o $(NAME) $(SRCS) $(LIBFT_FLAGS) -I $(INCS_DIR)

norm :
	norminette $(SRCS) $(INCS_DIR)

PHONY	: all clean fclean re bonus