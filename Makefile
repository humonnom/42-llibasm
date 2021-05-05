# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 16:14:23 by juepark           #+#    #+#              #
#    Updated: 2021/05/05 19:37:10 by juepark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libasm.a

SRCS		= ft_write.s ft_read.s
OBJS		= $(SRCS:.s=.o)

NASM		= nasm
NASM_FLAGS	= -f macho64
FLAGS		= -Wall -Werror -Wextra
TEST		= test

%.o:		%.s
			@$(NASM) $(NASM_FLAGS) $<

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS)

clean:
			@rm -rf $(OBJS)

fclean:		clean
			@rm -rf $(NAME) $(TEST)

re:			fclean $(NAME)

test:		$(NAME)
			@gcc $(FLAGS) -L. -lasm -o $(TEST) main.c
			@./$(TEST) < Makefile

.PHONY:		clean fclean re test
