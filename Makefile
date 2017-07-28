##
## Makefile for gb in /home/tetra/en_cours/GB_emulator
## 
## Made by Arthur Josso
## Login   <arthur.josso@epitech.eu>
## 
## Started on  Sat Mar  4 13:32:29 2017 Arthur Josso
## Last update Fri Jul 28 19:01:33 2017 Arthur Josso
##

CC	=	gcc

NAME	=	GB_emulator

INC	=	./inc/

CFLAGS	+=	-I$(INC) -Wall -W -Wextra	\
		`sdl-config --cflags`

LDFLAGS	+=	`sdl-config --libs`

DEV_FLAG =	-g

S_ROOT	=	./src/

S_ACCES	=	$(S_ROOT)accessor/

S_INST	=	$(S_ROOT)instruction/

S_RUN	=	$(S_ROOT)run/

S_INT	=	$(S_ROOT)interrupt/

S_SCR	=	$(S_ROOT)screen/

S_MEM	=	$(S_ROOT)memory/

S_INPUT	=	$(S_ROOT)input/

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
		$(S_SCR)init.c		\
		$(S_SCR)refresh.c	\
		$(S_SCR)blit.c		\
		$(S_SCR)draw_line.c	\
		$(S_SCR)draw_bg.c	\
		$(S_INPUT)keys.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

%.o:		%.c
		@echo [Compiling]: $<
		@$(CC) $(DEV_FLAG) $(CFLAGS) -o $@ -c $<

all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
