# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rosfryd <rosfryd@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 00:40:54 by rosfryd           #+#    #+#              #
#    Updated: 2021/01/22 05:20:05 by rosfryd          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = base/ft_printf.c base/ft_printf_utils_1.c base/ft_printf_utils_3.c\
base/ft_printf_utils_2.c base/ft_printf_utils_4.c\
parser/ft_flag_parser.c parser/ft_precision_parser.c parser/ft_type_parser.c parser/ft_width_parser.c\
processor/ft_char_write.c processor/ft_pointer_write.c processor/ft_sm_and_big_x_write.c processor/ft_un_write.c\
processor/ft_int_write.c processor/ft_procent_write.c processor/ft_string_write.c

LIB = ./libft/libft.a

OBJ = $(SRC:.c=.o)

OBJcur = ft_precision_parser.o   ft_procent_write.o\
ft_printf.o             ft_sm_and_big_x_write.o\
ft_char_write.o         ft_printf_utils_1.o     ft_string_write.o\
ft_flag_parser.o        ft_printf_utils_2.o     ft_type_parser.o\
ft_int_write.o          ft_printf_utils_3.o     ft_un_write.o\
ft_pointer_write.o      ft_printf_utils_4.o     ft_width_parser.o

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	$(MAKE) -C libft
	cp $(LIB) ./$(NAME)
	gcc $(FLAGS) -c $(SRC) -I ./base
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(OBJcur)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean flean re
