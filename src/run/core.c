/*
** core.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jul 18 00:28:52 2017 Arthur Josso
** Last update Fri Jul 28 19:03:56 2017 Arthur Josso
*/

#include <unistd.h>
#include "core.h"
#include "opcode.h"
#include "misc.h"
#include "interrupt.h"
#include "screen.h"
#include "input.h"

//
#include <stdio.h>
//

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

      //
      printf("%s (PC=%x)\n", act_inst->desc, reg.PC);
      //usleep(1000000);
      //

      act_inst->func((t_parameter*)act_inst->param);
      reg.PC += act_inst->byte_size;

      refresh_clock_dependent_regs(act_inst->opcode, act_inst->nb_cycles);

      check_for_interrupts();

      check_for_inputs();

      screen_check_for_update();
    }
  return (true);
}
