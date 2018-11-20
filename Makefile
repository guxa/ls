# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/14 16:52:43 by jguleski          #+#    #+#              #
#    Updated: 2018/11/19 17:59:42 by jguleski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
BLIBFT = libft_funcs/
BLS = blstfuncs.c \
	  b_ls.c \
	  bls_printer.c \
	  ls_utilities.c \
	  getfiledata.c \
	  bls_permis.c \
	  sortargvs.c \

LIB = libft/libft.a

INCLUDES = -I. -Ilibft/includes
OBJECTS = $(SRC:%.c=%.o)

all:
		gcc -Wall -Wextra -Werror $(INCLUDES) $(BLS) $(LIB) -o ft_ls

%.o: %.c
		@gcc -Wall -Wextra -Werror -c -I$(BLIBFT) $< -o $@

$(NAME): $(OBJECTS) 
		@ar rc $(NAME) $(OBJECTS) 
		@ranlib $(NAME)
		@echo "your lib is ready"
		@#gcc -Wall -Wextra -Werror -o test $(SRC) -I.

debug:
		gcc -Wall -Wextra -Werror -g $(INCLUDES) $(BLS) $(LIB) -o test

clean:
		/bin/rm -f $(OBJECTS)

fclean:	clean
		/bin/rm -f $(NAME)
		@rm -f b_ls

re: fclean all
