/*
** vblank.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jul 24 00:59:04 2017 Arthur Josso
** Last update Wed Jul 26 02:18:18 2017 Arthur Josso
*/

#include "interrupt.h"
#include "screen.h"
#include "special_reg.h"
#include "memory.h"

bool			interrupt_lcdc(uint8_t elapsed_cycles)
{
  static t_screen_state	old_scr_state = SCR_HBLANK;
  t_spereg_stat * const	stat = (void*)&mem->raw[REG_STAT];
  bool			is_int;

  (void)elapsed_cycles;
  if (old_scr_state != screen.state &&
      GET_BIT(stat->interrupt, screen.state))
    is_int = true;
  else if (screen.line == mem->raw[REG_LYC] &&
	   GET_BIT(stat->interrupt, SCR_COINCIDENCE))
    is_int = true;
  else
    is_int = false;
  old_scr_state = screen.state;
  return (is_int);
}