/*
** core.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jul 25 01:19:04 2017 Arthur Josso
** Last update Tue Jul 25 03:08:30 2017 Arthur Josso
*/

#include "memory.h"
#include "interrupt.h"
#include "special_reg.h"
#include "opcode.h"
#include "instruction.h"

static void		execute_interrupt(t_int_type raised_int)
{
  static t_parameter	push_params[2] = {P_IREG_16(SP), P_REG_16(PC)};
  static t_parameter	jmp_params[2] = {P_RAW(0), P_RAW(CONDITION_NONE)};
  static const uint16_t	interrupt_addrs[INT_NBR] =
    { 0x0040, 0x0048, 0x0050, 0x0058, 0x0060 };

  mem->raw[REG_IF] = 0;
  inst_DI(NULL);
  inst_PUSH(push_params);
  jmp_params[0].raw = interrupt_addrs[raised_int];
  inst_JP(jmp_params);
}

void				check_for_interrupts(uint8_t elapsed_cycles)
{
  t_int_type                    act_int;
  t_int_type			raised_int;
  bool                          is_int_raised;
  static const t_interrupt      interrupts[INT_NBR] =
    {
      interrupt_vblank,
      interrupt_lcdc,
      interrupt_timer,
      interrupt_serial_io,
      interrupt_pin_transition,
    };

  raised_int = INT_NONE;
  act_int = INT_FIRST;
  while (act_int < INT_NBR)
    {
      is_int_raised = interrupts[act_int](elapsed_cycles);
      if (is_int_raised && mem->raw[REG_IF] == 0 &&
	  GET_FLAG(FLAG_I) && GET_BIT(REG_IE, act_int))
	{
	  SET_BIT(mem->raw[REG_IF], act_int);
	  raised_int = act_int;
	}
      act_int++;
    }
  if (raised_int != INT_NONE)
    execute_interrupt(raised_int);
}
