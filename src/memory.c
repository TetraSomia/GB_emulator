/*
** memory.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Mar  5 17:55:47 2017 Arthur Josso
** Last update Sun Mar  5 19:25:11 2017 Arthur Josso
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "misc.h"

t_memory	*mem;
t_registers	*reg;

uint8_t		get_byte(uint16_t addr)
{
  return (mem->raw[addr]);
}

uint16_t	get_word(uint16_t addr)
{
  return (*((uint16_t*)(mem->raw + addr)));
}

void		set_byte(uint16_t addr, uint8_t value)
{
  mem->raw[addr] = value;
  if (0xE000 <= addr && addr < 0xFE00)
    mem->raw[addr - 0x2000] = value;
  else if (0xC000 <= addr && addr < 0xDE00)
    mem->raw[addr + 0x2000] = value;
}

void		set_word(uint16_t addr, uint16_t value)
{
  uint16_t	*ptr;

  if (addr & 1)
    fprintf(stderr, "WARNING: set_word: address not aligned\n");
  ptr = (uint16_t*)(mem->raw + addr);
  *ptr = value;
  if (0xE000 <= addr && addr < 0xFE00)
    *(ptr - 0x2000) = value;
  else if (0xC000 <= addr && addr < 0xDE00)
    *(ptr + 0x2000) = value;
}

void		init_memory()
{
  mem = xalloc(sizeof(*mem));
  reg = xalloc(sizeof(*reg));
  reg->AF = 0x01B0;
  reg->BC = 0x0013;
  reg->DE = 0x00D8;
  reg->HL = 0x014D;
  reg->SP = 0xFFFE;
}

void		free_memory()
{
  free(reg);
  free(mem);
}

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
