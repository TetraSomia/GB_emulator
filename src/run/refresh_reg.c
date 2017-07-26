/*
** refresh_reg.c for gb in /home/tetra/GB
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jul 26 16:42:38 2017 Arthur Josso
** Last update Wed Jul 26 16:52:00 2017 Arthur Josso
*/

#include "opcode.h"
#include "cb_opcode.h"
#include "screen.h"

void		refresh_clock_dependent_regs(uint8_t last_opcode,
					     uint8_t cycles_duration)
{
  uint8_t	elapsed_cycles;

   if (last_opcode == 0xCB)
     elapsed_cycles = get_last_cb_inst_cycles();
   else
     elapsed_cycles = cycles_duration;
   refresh_screen_state(elapsed_cycles);
}