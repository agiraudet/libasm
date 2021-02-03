# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 22:59:36 by agiraude          #+#    #+#              #
#    Updated: 2021/02/03 13:36:58 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

SRCS_FILES	=	ft_strlen.s \
				ft_strcpy.s \
				ft_write.s \
				ft_read.s \
				ft_strdup.s \
				ft_strcmp.s \
				bonus/ft_list_create_elem_bonus.s \
				bonus/ft_list_swap_bonus.s \
				bonus/ft_list_remove_if_bonus.s \
				bonus/ft_list_delone_bonus.s \
				bonus/ft_list_push_front_bonus.s \
				bonus/ft_list_size_bonus.s \
				bonus/ft_list_sort_bonus.s \
				bonus/ft_atoi_base_bonus.s \
				bonus/ft_isspace_bonus.s \
				bonus/ft_getindex_bonus.s \
				bonus/ft_checkbase_bonus.s

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

fclean:			clean
				rm -f $(NAME)

re:				fclean all

test:			all
				clang -Wall -Wextra main.c -I includes -L . -lasm -o test

bonus:			all
				clang -Wall -Wextra bonus_main.c -I includes -L . -lasm -o test_bonus

list:			all
				clang -Wall -Wextra list.c -I includes -L . -lasm -o list_test

.PHONY:			all clean fclean re
