/*
** core.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jul 18 00:28:52 2017 Arthur Josso
** Last update Tue Jul 25 03:19:04 2017 Arthur Josso
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

bool			emu_run()
{
  const t_instruction	*act_inst;
  uint8_t		elapsed_cycles;

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

      if (act_inst->opcode == 0xCB)
	elapsed_cycles = get_last_cb_inst_cycles();
      else
	elapsed_cycles = act_inst->nb_cycles;
      refresh_screen_state(elapsed_cycles);
      check_for_interrupts(elapsed_cycles);

      //
      if (act_inst->opcode != 0x18)
	printf("%s\n", act_inst->desc);
      //usleep(10);
      //
    }
  return (true);
}
