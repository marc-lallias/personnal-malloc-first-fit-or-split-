##
## Makefile for  in /home/darkmark/rendu/PSU_2016_malloc
## 
## Made by DarKmarK
## Login   <marc.lallias@epitech.eu>
## 
## Started on  Tue Jan 24 12:11:07 2017 DarKmarK
## Last update Tue Jan 24 19:44:25 2017 DarKmarK
##

NAME	=	program

CC	=	gcc

RM	=	rm -rf

SRCS	=	./test/test_main.c		\

LIBSRC	=	./src/malloc.c			\

OBJS	=	$(SRCS:.c=.o)

LIBOBJ  =	$(LIBSRC:.c=.o)

TARGET	=	libmy_malloc.so

DESTDIR	=	./lib/

CFLAGS  = -fPIC -g
CFLAGS += -W -Wall -Wextra

LDFLAGS = -shared

all: $(TARGET)


$(TARGET): $(LIBOBJ)
	$(CC) $(CFLAGS)  $(LDFLAGS)  $(LIBSRC) -o $(DESTDIR)$(TARGET)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -libmy_malloc.so -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
