/*
** vblank.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jul 24 00:59:04 2017 Arthur Josso
** Last update Wed Jul 26 17:55:10 2017 Arthur Josso
*/

#include "memory.h"
#include "interrupt.h"
#include "special_reg.h"

static bool	timer_overflow = false;

void			refresh_timer_state(uint8_t elapsed_cycles)
{
  static uint32_t	clock = 0;
  t_spereg_tac * const	tac_reg = (void*)&mem->raw[REG_TAC];
  static const uint16_t	durations[] = {0x100, 0x04, 0x10, 0x40};

  if (!tac_reg->run)
    return;
  clock += elapsed_cycles;
  while (clock >= durations[tac_reg->freq])
    {
      if (mem->raw[REG_TIMA] == 0xFF)
	{
	  timer_overflow = true;
	  mem->raw[REG_TIMA] = mem->raw[REG_TMA];
	}
      else
	mem->raw[REG_TIMA]++;
      clock -= durations[tac_reg->freq];
    }
}

bool			interrupt_timer()
{
  if (timer_overflow)
    {
      timer_overflow = false;
      return (true);
    }
  return (false);
}
