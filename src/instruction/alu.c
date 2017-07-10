/*
** alu.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jul 10 22:27:17 2017 Arthur Josso
** Last update Tue Jul 11 00:28:26 2017 Arthur Josso
*/

#include "opcode.h"
#include "memory.h"

void		inst_ADD(t_parameter *param)
{
  uint16_t	a;
  uint16_t	b;

  a = get_param_value(param);
  b = get_param_value(param + 1);
  set_param_value(param, a + b);
  CONDITION_FLAG(FLAG_Z, get_param_value(param) == 0);
  RESET_FLAG(FLAG_N);
  CONDITION_FLAG(FLAG_C, IS_CARRY(a, b, PARAM_SIZE(param)));
}

void		inst_ADD_SP(t_parameter *param)
{
  int8_t	offset;

  offset = get_param_value(param + 1);
  CONDITION_FLAG(FLAG_C, IS_CARRY(reg.SP, offset, 16));
  reg.SP += offset;
  RESET_FLAG(FLAG_Z);
  RESET_FLAG(FLAG_N);
}
