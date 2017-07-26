/*
** memory.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Mar  5 17:55:47 2017 Arthur Josso
** Last update Wed Jul 26 16:58:41 2017 Arthur Josso
*/

#include <stdlib.h>
#include "memory.h"
#include "opcode.h"

void		free_memory()
{
  if (mem)
    free(mem);
  if (instructions)
    free(instructions);
}
