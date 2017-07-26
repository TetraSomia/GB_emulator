/*
** memory.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Mar  5 17:55:47 2017 Arthur Josso
** Last update Wed Jul 26 16:58:24 2017 Arthur Josso
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "memory.h"

bool		dump_file(const char *path)
{
  FILE		*file;
  struct stat	file_stat;

  if (stat(path, &file_stat) != -1 && !S_ISREG(file_stat.st_mode))
    {
      fprintf(stderr, "%s: not a regular file\n", path);
      return (false);
    }
  file = fopen(path, "r");
  if (file == NULL)
    {
      fprintf(stderr, "%s: no such file\n", path);
      return (false);
    }
  if (fstat(fileno(file), &file_stat) == -1 || !S_ISREG(file_stat.st_mode))
    {
      fprintf(stderr, "%s: not a regular file\n", path);
      return (false);
    }
  fseek(file, 0, SEEK_END);
  if (ftell(file) != sizeof(mem->ROM))
    {
      fprintf(stderr, "%s: the ROM should be 32kB long\n", path);
      return (false);
    }
  fseek(file, 0, SEEK_SET);
  if (fread(mem->ROM, 1, sizeof(mem->ROM), file) != sizeof(mem->ROM))
    {
      fprintf(stderr, "ERROR: fread failed\n");
      return (false);
    }
  fclose(file);
  return (true);
}
