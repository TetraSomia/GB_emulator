/*
** misc.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Mar  5 18:11:24 2017 Arthur Josso
** Last update Sun Mar  5 18:16:40 2017 Arthur Josso
*/

#include <stdlib.h>

void	*xalloc(size_t size)
{
  void	*ptr;

  ptr = calloc(1, size);
  if (ptr == NULL)
    exit(1);
  return (ptr);
}
