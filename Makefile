##
## Makefile for gb in /home/tetra/en_cours/GB_emulator
## 
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Sat Mar  4 13:32:29 2017 Arthur Josso
## Last update Sun Jul  9 21:34:20 2017 Arthur Josso
##

CC	=	gcc -g

NAME	=	a.out

INC	=	./inc/

CFLAGS	+=	-I$(INC) -Wall -W -Wextra

LDFLAGS	+=

S_ROOT	=	./src/

SRC	=	$(S_ROOT)main.c 	\
		$(S_ROOT)memory.c 	\
		$(S_ROOT)misc.c 	\
		$(S_ROOT)instruction.c 	\
		$(S_ROOT)opcode.c	\
		$(S_ROOT)param_op.c

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
