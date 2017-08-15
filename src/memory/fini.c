/*
** memory.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Mar  5 17:55:47 2017 Arthur Josso
** Last update Wed Aug 16 01:14:23 2017 Arthur Josso
*/

#include <stdlib.h>
#include "memory.h"
#include "opcode.h"
#include "screen.h"

void		free_memory()
{
  if (screen.pix_scr.array)
    free(screen.pix_scr.array);
  if (screen.pix_bg.array)
    free(screen.pix_bg.array);
  SDL_Quit();
  if (mem)
    free(mem);
  if (instructions)
    free(instructions);
}
