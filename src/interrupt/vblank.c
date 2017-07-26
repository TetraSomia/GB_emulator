/*
** vblank.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jul 24 00:59:04 2017 Arthur Josso
** Last update Wed Jul 26 21:29:20 2017 Arthur Josso
*/

#include "interrupt.h"
#include "screen.h"

bool			interrupt_vblank()
{
  bool			is_int;

  if (screen.changed_state && screen.state == SCR_VBLANK)
    is_int = true;
  else
    is_int = false;
  return (is_int);
}
