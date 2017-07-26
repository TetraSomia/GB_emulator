##
## Makefile for gb in /home/tetra/en_cours/GB_emulator
## 
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Sat Mar  4 13:32:29 2017 Arthur Josso
## Last update Wed Jul 26 16:57:52 2017 Arthur Josso
##

CC	=	gcc

NAME	=	GB_emulator

INC	=	./inc/

CFLAGS	+=	-I$(INC) -Wall -W -Wextra -g

LDFLAGS	+=

S_ROOT	=	./src/

S_ACCES	=	$(S_ROOT)accessor/

S_INST	=	$(S_ROOT)instruction/

S_RUN	=	$(S_ROOT)run/

S_INT	=	$(S_ROOT)interrupt/

S_SCR	=	$(S_ROOT)screen/

S_MEM	=	$(S_ROOT)memory/

SRC	=	$(S_ROOT)main.c 	\
		$(S_ROOT)misc.c 	\
		$(S_MEM)init.c		\
		$(S_MEM)dump.c		\
		$(S_MEM)fini.c		\
		$(S_ACCES)memory.c	\
		$(S_ACCES)parameter.c	\
		$(S_INST)opcode.c	\
		$(S_INST)load.c		\
		$(S_INST)stack.c	\
		$(S_INST)alu.c		\
		$(S_INST)cb_prefix.c	\
		$(S_INST)misc.c		\
		$(S_INST)rotation.c	\
		$(S_INST)jump.c		\
		$(S_INST)condition.c	\
		$(S_RUN)core.c		\
		$(S_RUN)refresh_reg.c	\
		$(S_INT)core.c		\
		$(S_INT)vblank.c	\
		$(S_INT)lcdc.c		\
		$(S_INT)timer.c		\
		$(S_INT)serial_io.c	\
		$(S_INT)pin_trans.c	\
		$(S_SCR)refresh.c

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
