/*
** memory.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Mar  5 17:55:47 2017 Arthur Josso
** Last update Tue Jul 18 01:37:03 2017 Arthur Josso
*/

#include "memory.h"
#include "misc.h"

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
    emu_warn("set_word", "Address not aligned");
  ptr = (uint16_t*)(mem->raw + addr);
  *ptr = value;
  if (0xE000 <= addr && addr < 0xFE00)
    *(ptr - 0x2000) = value;
  else if (0xC000 <= addr && addr < 0xDE00)
    *(ptr + 0x2000) = value;
}
