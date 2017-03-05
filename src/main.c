/*
** main.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Mar  4 13:34:04 2017 Arthur Josso
** Last update Sun Mar  5 19:27:28 2017 Arthur Josso
*/

#include <stdio.h>
#include "memory.h"

static int	usage(const char *binary)
{
  fprintf(stderr, "Usage: %s [rom]\n", binary);
  return (1);
}

int	main(int ac, char **av)
{
  if (ac != 2)
    return (usage(av[0]));
  init_memory();
  if (dump_file(av[1]) == false)
    return (1);
  free_memory();
  return (0);
}
