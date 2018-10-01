# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/14 16:52:43 by jguleski          #+#    #+#              #
#    Updated: 2018/09/23 16:02:20 by jguleski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
BLIBFT = libft_funcs/
SRC = b_printf.c \
	  bprintf_parser.c \
	  findarg.c \
	  ft_putstr.c \
	  ft_newstr.c \
	  ft_itoa.c \
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
	  #../bprintf-main.c \
	  #testmain.c \
	  #$(BLIBFT)imetonafunkcijata
HEADER = includes
#OBJECTS = $(SRC:.c=.o)

all:	
		gcc -Wall -Wextra -Werror -o test b_ls.c -I.

$(NAME):
		gcc -Wall -Wextra -Werror -o test $(SRC) -I.
#@gcc -Wall -Wextra -Werror -c $(SRC) -I.
#@ar rc $(NAME) $(OBJECTS) 
#@ranlib $(NAME)
#@echo "your lib is ready"

debug:
		gcc -Wall -Wextra -Werror -g -I. b_ls.c -o test
		#gcc -Wall -Wextra -Werror -g -o test $(SRC) -I.

clean:
		/bin/rm -f $(OBJECTS)

fclean:	clean
		/bin/rm -f $(NAME)

re: fclean all
