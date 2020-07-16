# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bmans <bmans@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/14 14:00:33 by bmans         #+#    #+#                  #
#    Updated: 2020/07/16 11:21:20 by bmans         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = asm_test
NAME_IN = main.c
LIB = libasm.a
HEADER = libasm.h
SRCS = ft_write.s ft_read.s ft_strlen.s ft_strcpy.s ft_strcmp.s
OBJS = $(SRCS:.s=.o)
NASM_FLAGS = -fmacho64
CC = gcc
CC_FLAGS = 
NASM_PATH = ./nasm/nasm

all: $(NAME)

%.o: %.s
	$(NASM_PATH) $(NASM_FLAGS) $<

$(NAME): $(OBJS)
	ar -rc $(LIB) $(OBJS) 
	gcc $(CC_FLAGS) $(NAME_IN) -L. -lasm -I. -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(LIB)
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean
