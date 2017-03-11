##
## Makefile for gb in /home/tetra/en_cours/GB_emulator
## 
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Sat Mar  4 13:32:29 2017 Arthur Josso
## Last update Sat Mar 11 21:33:46 2017 Arthur Josso
##

CC	=	gcc -g

NAME	=	a.out

INC	=	./inc/

CFLAGS	+=	-I$(INC) -Wall -W -Wextra

LDFLAGS	+=

SRC	=	./src/main.c \
		./src/memory.c \
		./src/misc.c \
		./src/instruction.c \
		./src/opcode.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
