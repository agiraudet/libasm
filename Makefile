# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 22:59:36 by agiraude          #+#    #+#              #
#    Updated: 2021/02/02 18:28:33 by agiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

SRCS_FILES	=	ft_strlen.s \
				ft_strcpy.s \
				ft_write.s \
				ft_read.s \
				ft_strdup.s \
				ft_strcmp.s \
				bonus/ft_list_create_elem.s \
				bonus/ft_list_swap.s \
				bonus/ft_list_remove_if.s \
				bonus/ft_list_delone.s \
				bonus/ft_list_push_front.s \
				bonus/ft_list_size.s \
				bonus/ft_list_sort.s \
				bonus/ft_atoi.s \
				bonus/ft_isspace.s \
				bonus/ft_getindex.s \
				bonus/ft_checkbase.s

SRCS_DIR	=	srcs/

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS		=	$(SRCS:.s=.o)

NASM		=	nasm

ASM_FLAGS	=	-f elf64 -gdwarf

%.o:			%.s
				$(NASM) $(ASM_FLAGS) $< -o $(<:.s=.o)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

all:			$(NAME)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

test:			all
				clang -Wall -Wextra -g main.c -I includes -L . -lasm -o test

bonus:			all
				clang -Wall -Wextra -g bonus_main.c -I includes -L . -lasm -o test_bonus

list:			all
				clang -Wall -Wextra -g list.c -I includes -L . -lasm -o list_test

.PHONY:			all clean fclean re
