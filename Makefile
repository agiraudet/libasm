# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 22:59:36 by agiraude          #+#    #+#              #
#    Updated: 2021/01/25 18:06:23 by agiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

SRCS_FILES	=	ft_strlen.s \
				ft_strcpy.s \
				ft_write.s \
				ft_strcmp.s

SRCS_DIR	=	srcs/

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS		=	$(SRCS:.s=.o)

NASM		=	nasm

ASM_FLAGS	=	-f elf64

%.o:			%.s
				$(NASM) $(ASM_FLAGS) $< -o $(<:.s=.o)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

all:			$(NAME)

clean:
				rm -f $(OBJS)

flcean:			clean
				rm -f $(NAME)

re:				flcean all

test:			all
				clang -Wall -Wextra -g main.c -I includes -L . -lasm -o test

.PHONY:			all clean fclean re
