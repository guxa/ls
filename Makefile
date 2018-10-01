# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/14 16:52:43 by jguleski          #+#    #+#              #
#    Updated: 2018/09/30 20:03:07 by jguleski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
BLIBFT = libft_funcs/
BLS = blstfuncs.c \
	  b_ls.c \
	  bls_printer.c \
	  cleanlist.c \
	  getfiledata.c \
	  bls_permis.c \

SRC = $(BLIBFT)b_printf.c \
	  $(BLIBFT)bprintf_parser.c \
	  $(BLIBFT)findarg.c \
	  $(BLIBFT)ft_putstr.c \
	  $(BLIBFT)ft_newstr.c \
	  $(BLIBFT)ft_itoa.c \
	  $(BLIBFT)ft_isdigit.c \
	  $(BLIBFT)ft_memset.c \
	  $(BLIBFT)ft_strchr.c \
	  $(BLIBFT)ft_strcmp.c \
	  $(BLIBFT)ft_strcpy.c \
	  $(BLIBFT)ft_strdup.c \
	  $(BLIBFT)ft_strlen.c \
	  $(BLIBFT)ft_strncpy.c \
	  $(BLIBFT)ft_tolower.c \
	  $(BLIBFT)ft_toupper.c \
	  $(BLIBFT)ft_memdel.c \
	  #../bprintf-main.c \
	  #testmain.c \
	  #$(BLIBFT)imetonafunkcijata
HEADER = includes
OBJECTS = $(SRC:%.c=%.o)

all: $(NAME)
		gcc -Wall -Wextra -Werror -I. $(BLS) $(NAME) -o b_ls

%.o: %.c
		@gcc -Wall -Wextra -Werror -c -I$(BLIBFT) $< -o $@

$(NAME): $(OBJECTS) 
		@ar rc $(NAME) $(OBJECTS) 
		@ranlib $(NAME)
		@echo "your lib is ready"
		@#gcc -Wall -Wextra -Werror -o test $(SRC) -I.

debug:
		gcc -Wall -Wextra -Werror -g -I. $(BLS) $(NAME) -o test

clean:
		/bin/rm -f $(OBJECTS)

fclean:	clean
		/bin/rm -f $(NAME)

re: fclean all
