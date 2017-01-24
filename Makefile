##
## Makefile for  in /home/darkmark/rendu/PSU_2016_malloc
## 
## Made by DarKmarK
## Login   <marc.lallias@epitech.eu>
## 
## Started on  Tue Jan 24 12:11:07 2017 DarKmarK
## Last update Tue Jan 24 12:12:56 2017 DarKmarK
##

NAME	=	program

CC	=	gcc

RM	= rm -rf

SRCS	= 	my_malloc.c	\
		main.c		\

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
