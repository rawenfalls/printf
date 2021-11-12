# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 21:36:09 by eraynald          #+#    #+#              #
#    Updated: 2021/10/25 17:56:54 by eraynald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

LIST	=	ft_printf.c printf_dop.c printf_dop2.c

LIST_B	=	

OBJ	=	$(patsubst %.c,%.o,$(LIST))
OBJ_B	=	$(patsubst %.c,%.o,$(LIST_B))

D_FILES	=	$(patsubst %.c,%.d,$(LIST) $(LIST_B))

OPTFLAGS	=	-o2
FLAGS	=	-Wall -Wextra -Werror

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	make -C libft
	cp libft/libft.a ./$(NAME)
	ar rcs $(NAME) $?

%.o	:	%.c
	gcc $(FLAGS) $(OPTFLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

bonus	:
	@make OBJ="$(OBJ_B)" all

clean	:
	@rm -f $(OBJ) $(OBJ_B) $(D_FILES)
	make clean -C libft

fclean	:	clean
	@rm -f $(NAME)
	make fclean -C libft

re	:	fclean all

.PHONY	:	all clean fclean re bonus