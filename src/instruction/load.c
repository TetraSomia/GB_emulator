/*
** instruction.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Mar 11 19:42:14 2017 Arthur Josso
** Last update Sun Jul  9 23:34:46 2017 Arthur Josso
*/

#include "opcode.h"
#include "memory.h"

void	inst_LD(t_parameter *param)
{
  set_param_value(param, get_param_value(param + 1));
}

void	inst_LDH(t_parameter *param)
{
  if (param[0].addr == &reg.A)
    set_param_value(param, get_byte(get_param_value(param) + 0xFF00));
  else
    set_byte(get_byte(get_param_value(param) + 0xFF00),
	     get_param_value(param + 1));
}

void    inst_LDD(t_parameter *param)
{
  set_param_value(param, get_param_value(param + 1));
  reg.HL--;
}

void    inst_LDI(t_parameter *param)
{
  set_param_value(param, get_param_value(param + 1));
  reg.HL++;
}

void	inst_LDHL(t_parameter *param)
{
  reg.HL = reg.SP + ((int8_t)get_param_value(param + 1));
  RESET_FLAG(FLAG_Z);
  RESET_FLAG(FLAG_N);
  // flag H & C
}
