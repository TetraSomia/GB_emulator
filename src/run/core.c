/*
** core.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jul 18 00:28:52 2017 Arthur Josso
** Last update Tue Jul 18 18:56:46 2017 Arthur Josso
*/

#include <unistd.h>
#include "memory.h"
#include "opcode.h"
#include "misc.h"

//
#include <stdio.h>
//

static uint64_t	clock_cycles;

void	emu_add_clock_cycles(uint8_t nbr)
{
  clock_cycles += nbr;
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
      printf("%s\n", act_inst->desc);
      act_inst->func((t_parameter*)act_inst->param);
      reg.PC += act_inst->byte_size;
      usleep(1000);
    }
  return (true);
}
