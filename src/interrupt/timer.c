/*
** vblank.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jul 24 00:59:04 2017 Arthur Josso
** Last update Mon Jul 24 01:02:40 2017 Arthur Josso
*/

#include "interrupt.h"

bool	interrupt_timer(uint8_t elapsed_cycles)
{
  (void)elapsed_cycles;
  return (false);
}
