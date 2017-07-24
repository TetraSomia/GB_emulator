/*
** core.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jul 18 00:28:52 2017 Arthur Josso
** Last update Tue Jul 25 00:29:20 2017 Arthur Josso
*/

#include <unistd.h>
#include "memory.h"
#include "opcode.h"
#include "misc.h"
#include "cb_opcode.h"
#include "interrupt.h"
#include "screen.h"

//
#include <stdio.h>
//

static void		check_for_interrupts(const t_instruction *last_inst)
{
  uint8_t			elapsed_cycles;
  t_int_type			act_int;
  bool				is_int_raised;
  static const t_interrupt	interrupts[INT_NBR] =
    {
      interrupt_vblank,
      interrupt_lcdc,
      interrupt_timer,
      interrupt_serial_io,
      interrupt_pin_transition,
    };

  if (last_inst->opcode == 0xCB)
    elapsed_cycles = get_last_cb_inst_cycles();
  else
    elapsed_cycles = last_inst->nb_cycles;
  refresh_screen_state(elapsed_cycles);
  act_int = INT_FIRST;
  while (act_int < INT_NBR)
    {
      is_int_raised = interrupts[act_int](elapsed_cycles);
      if (GET_FLAG(FLAG_I) && is_int_raised)
	RAISE_INTERRUPT(act_int);
      act_int++;
    }
}

bool			emu_run()
{
  const t_instruction	*act_inst;

  while (1)
    {
      act_inst = instructions[ACT_OPCODE];
      if (!act_inst)
	{
	  emu_warn("emu_run", "Unknown opcode");
	  reg.PC++;
	  continue;
	}
      act_inst->func((t_parameter*)act_inst->param);
      reg.PC += act_inst->byte_size;
      check_for_interrupts(act_inst);
      //
      printf("%s\n", act_inst->desc);
      usleep(100);
      //
    }
  return (true);
}
