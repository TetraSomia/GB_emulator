##
## Makefile for gb in /home/tetra/en_cours/GB_emulator
## 
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Sat Mar  4 13:32:29 2017 Arthur Josso
## Last update Mon Jul 10 22:27:42 2017 Arthur Josso
##

CC	=	gcc -g

NAME	=	a.out

INC	=	./inc/

CFLAGS	+=	-I$(INC) -Wall -W -Wextra

LDFLAGS	+=

S_ROOT	=	./src/

S_ACCES	=	$(S_ROOT)accessor/

S_INST	=	$(S_ROOT)instruction/

SRC	=	$(S_ROOT)main.c 	\
		$(S_ROOT)memory.c 	\
		$(S_ROOT)misc.c 	\
		$(S_ACCES)memory.c	\
		$(S_ACCES)parameter.c	\
		$(S_INST)opcode.c	\
		$(S_INST)load.c		\
		$(S_INST)stack.c	\
		$(S_INST)alu.c

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
