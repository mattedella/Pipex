# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdella-r <mdella-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 11:41:56 by mdella-r          #+#    #+#              #
#    Updated: 2024/02/12 14:34:28 by mdella-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = mandatory/pipex.c mandatory/pipex_utils.c mandatory/split.c mandatory/utils.c mandatory/error.c
BSRCS = bonus/error_bonus.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/here_doc_bonus.c bonus/pipex_bonus.c bonus/pipex_bonus_utils.c bonus/split.c bonus/utils.c 
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
INCLUDES = .
HEADERS = pipex.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
NAME = pipex

all: $(NAME)

bonus: $(BOBJS)
				@$(CC) $(CFLAGS) $(BOBJS) -o $(NAME)
				@echo compiled $(NAME)				

$(NAME): $(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo compiled $(NAME)

%.o: %.c $(HEADERS)
				@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
				@$(RM) $(OBJS) $(BOBJS)
				@echo removed object files

fclean: clean
				@$(RM) $(NAME)
				@echo removed $(NAME)

re: fclean all

.PHONY: all clean fclean re
