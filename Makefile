##
## Makefile for  in /home/darkmark/rendu/PSU_2016_malloc
## 
## Made by DarKmarK
## Login   <marc.lallias@epitech.eu>
## 
## Started on  Tue Jan 24 12:11:07 2017 DarKmarK
## Last update Wed Jan 25 11:16:28 2017 DarKmarK
##

NAME	=	program

CC	=	gcc

RM	=	rm -rf

SRCS	=	./test/test_main.c		\

LIBSRC	=	./src/malloc.c			\

OBJ	=	$(SRCS:.c=.o)

LIBOBJ  =	$(LIBSRC:.c=.o)

TARGET	=	libmy_malloc.so

DESTDIR	=	.

CFLAGS = -W -Wall -Wextra
CFLAGS += -fPIC

LDFLAGS = -shared

all: $(TARGET) $(NAME)


$(TARGET): $(LIBOBJ)
	$(CC) $(CFLAGS)  $(LDFLAGS)  $(LIBSRC) -o $(DESTDIR)$(TARGET)

$(NAME): $(OBJ)
	 $(CC) $(OBJ) -L$(DESTDIR)$(TARGET) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

lclean:
	$(RM) $(LIBOBJ)

lfclean: lclean
	$(RM) $(DESTDIR)$(TARGET)

re: fclean lfclean all

.PHONY: all clean lclean lfclean fclean re
