# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/02 11:17:10 by evalenti          #+#    #+#              #
#    Updated: 2023/07/08 12:02:10 by evalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME =  libftprintf.a

SRCS = $(wildcard f*.c)
OBJS = $(SRCS:.c=.o)

CC		= cc
RM		= /bin/rm -rf
CFLAGS	= -Wall -Wextra -Werror -I $(INC)

INC	= ./
CL = ar -rc
RL = ar -s

$(NAME):	$(OBJS)
	$(CL)	$(NAME)	$(OBJS)
	$(RL)	$(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM)	$(NAME)

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader *.c
	norminette -R CheckDefine *.h

.PHONY: all clean fclean re
