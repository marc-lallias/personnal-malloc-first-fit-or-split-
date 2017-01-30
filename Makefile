##
## Makefile for  in /home/darkmark/rendu/PSU_2016_malloc
## 
## Made by DarKmarK
## Login   <marc.lallias@epitech.eu>
## 
## Started on  Tue Jan 24 12:11:07 2017 DarKmarK
## Last update Sun Jan 29 16:01:45 2017 DarKmarK
##

NAME	=	program

CC	=	gcc

RM	=	rm -rf

SRCS	=	./test/test_main.c		\
		./src/malloc.c			\
		./src/free.c			\

LIBSRC	=	./src/malloc.c			\

OBJ	=	$(SRCS:.c=.o)

LIBOBJ  =	$(LIBSRC:.c=.o)

TARGET	=	libmy_malloc.so

DESTDIR	=	./

CFLAGS =
CFLAGS += -fPIC

LDFLAGS = -shared

all: $(TARGET) $(NAME)


$(TARGET): $(LIBOBJ)
	$(CC) $(CFLAGS)  $(LDFLAGS)  $(LIBOBJ) -o $(DESTDIR)$(TARGET)

$(NAME): $(OBJ)
	 $(CC) $(OBJ) -L$(DESTDIR)$(TARGET)-g3 -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

lclean:
	$(RM) $(LIBOBJ)

lfclean: lclean
	$(RM) $(DESTDIR)$(TARGET)

re: fclean lfclean all

.PHONY: all clean lclean lfclean fclean re
