/*
** memory.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Mar  5 17:55:47 2017 Arthur Josso
** Last update Fri Jul 28 00:53:02 2017 Arthur Josso
*/

#include <stdlib.h>
#include "memory.h"
#include "opcode.h"
#include "screen.h"

void		free_memory()
{
  if (screen.pixels)
    free(screen.pixels);
  SDL_Quit();
  if (mem)
    free(mem);
  if (instructions)
    free(instructions);
}
