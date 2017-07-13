##
## Makefile for gb in /home/tetra/en_cours/GB_emulator
## 
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Sat Mar  4 13:32:29 2017 Arthur Josso
## Last update Thu Jul 13 21:00:28 2017 Arthur Josso
##

CC	=	gcc -g

NAME	=	GB_emulator

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
		$(S_INST)alu.c		\
		$(S_INST)cb_prefix.c	\
		$(S_INST)misc.c		\
		$(S_INST)rotation.c

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
