/*
** vblank.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jul 24 00:59:04 2017 Arthur Josso
** Last update Tue Jul 25 02:09:14 2017 Arthur Josso
*/

#include "interrupt.h"
#include "screen.h"

bool			interrupt_vblank(uint8_t elapsed_cycles)
{
  static t_screen_state	old_scr_state = SCR_HBLANK;
  bool			is_int;

  (void)elapsed_cycles;
  if (old_scr_state != screen.state && screen.state == SCR_VBLANK)
    is_int = true;
  else
    is_int = false;
  old_scr_state = screen.state;
  return (is_int);
}
