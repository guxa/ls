# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/14 16:52:43 by jguleski          #+#    #+#              #
#    Updated: 2018/11/19 22:12:00 by jguleski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_ls

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror

BLS = blstfuncs.c \
	  b_ls.c \
	  bls_printer.c \
	  ls_utilities.c \
	  getfiledata.c \
	  bls_permis.c \
	  sortargvs.c \

INCLUDES = -I. -Ilibft/includes -Ilibft/printf

OBJECTS_DIR = objects/
OBJ_LIST = $(BLS:%.c=%.o)
OBJECTS	= $(addprefix $(OBJECTS_DIR), $(OBJ_LIST))

all: $(NAME)

$(NAME): $(LIBFT) $(BLS) $(OBJECTS_DIR) $(OBJECTS)
		 @gcc $(FLAGS) $(INCLUDES) $(OBJECTS) $(LIBFT) -o $(NAME)
		 @echo "ft_ls is ready"

$(LIBFT):
		@echo "Compiling stuff.. you know how it goes..."
		@make -C libft/

$(OBJECTS_DIR)%.o: %.c
		@gcc $(FLAGS) -c $(INCLUDES) $< -o $@

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

debug:
		gcc $(FLAGS) -g $(INCLUDES) $(BLS) $(LIBFT) -o test

clean:
		@make -C libft/ clean
		@rm -rf $(OBJECTS_DIR)

fclean:	clean
		@make -C libft/ fclean
		@rm -f $(NAME)
		@rm -f b_ls

re: fclean all
