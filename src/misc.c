/*
** misc.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Mar  5 18:11:24 2017 Arthur Josso
** Last update Sun Jul  9 21:37:01 2017 Arthur Josso
*/

#include <stdlib.h>
#include <stdio.h>

void	*xalloc(size_t size)
{
  void	*ptr;

  ptr = calloc(1, size);
  if (ptr == NULL)
    exit(1);
  return (ptr);
}

void	emu_warn(const char *func, const char *msg)
{
  fprintf(stderr, "WARNING : in \"%s\" : %s\n", func, msg);
}
