/*
** main.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Mar  4 13:34:04 2017 Arthur Josso
** Last update Fri Jul 28 00:43:38 2017 Arthur Josso
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "core.h"
#include "screen.h"

static void	sig_handler(int sig)
{
  if (sig == SIGINT)
    {
      fprintf(stderr, "\nClosing Emulator...\n");
      exit(0);
    }
}

static int	usage(const char *binary)
{
  fprintf(stderr, "Usage: %s [rom]\n", binary);
  return (1);
}

int	main(int ac, char **av)
{
  if (ac != 2)
    return (usage(av[0]));
  atexit(&free_memory);
  signal(SIGINT, &sig_handler);
  init_memory();
  if (dump_file(av[1]) == false)
    return (1);
  if (screen_init() == false)
    return (1);
  emu_run();
  return (0);
}
