# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcampos- <pcampos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 12:12:49 by pcampos-          #+#    #+#              #
#    Updated: 2022/09/26 15:27:33 by pcampos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################## Program #################

NAME =			philo

################## COLORS ##################

--GRN	=		\033[32m
--RED	=		\033[31m
--WHT	=		\033[39m

################## TERMINAL ################

RM		=		rm -f

################## COMPILER ################

CC		=		cc
CFLAGS	=		-Wall -Werror -Wextra -g -fsanitize=address

################## FILES ###################

SRCS	=		srcs/philo_main.c \
				srcs/utils.c \
				srcs/init.c

OBJS	=		$(SRCS:.c=.o)	

################## RULES ###################

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -pthread $(OBJS) -o $(NAME)

################## CLEAN ###################

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re