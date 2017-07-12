/*
** alu.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jul 10 22:27:17 2017 Arthur Josso
** Last update Wed Jul 12 18:26:22 2017 Arthur Josso
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
  if (IS_8_PARAM(param))
    CONDITION_FLAG(FLAG_Z, get_param_value(param) == 0);
  RESET_FLAG(FLAG_N);
  CONDITION_FLAG(FLAG_C, IS_CARRY(a, b, PARAM_SIZE(param)));
}

void		inst_ADC(t_parameter *param)
{
  uint16_t	sum;

  sum = get_param_value(param) + get_param_value(param + 1) + GET_FLAG(FLAG_C);
  set_param_value(param, sum);
  CONDITION_FLAG(FLAG_Z, get_param_value(param) == 0);
  RESET_FLAG(FLAG_N);
  CONDITION_FLAG(FLAG_C, sum > 0xFF);
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

void		inst_SUB(t_parameter *param)
{
  uint8_t	a;
  uint8_t	b;

  a = get_param_value(param);
  b = get_param_value(param + 1);
  set_param_value(param, a - b);
  CONDITION_FLAG(FLAG_Z, a == b);
  SET_FLAG(FLAG_N);
  CONDITION_FLAG(FLAG_C, a < b);
}

void		inst_SBC(t_parameter *param)
{
  uint8_t	a;
  uint8_t	b;

  a = get_param_value(param);
  b = get_param_value(param + 1) + GET_FLAG(FLAG_C);
  set_param_value(param, a - b);
  CONDITION_FLAG(FLAG_Z, a == b);
  SET_FLAG(FLAG_N);
  CONDITION_FLAG(FLAG_C, a < b);
}

void		inst_AND(t_parameter *param)
{
  uint8_t	result;

  result = get_param_value(param) & get_param_value(param + 1);
  set_param_value(param, result);
  CONDITION_FLAG(FLAG_Z, result == 0);
  RESET_FLAG(FLAG_N);
  RESET_FLAG(FLAG_C);
}

void		inst_OR(t_parameter *param)
{
  uint8_t	result;

  result = get_param_value(param) | get_param_value(param + 1);
  set_param_value(param, result);
  CONDITION_FLAG(FLAG_Z, result == 0);
  RESET_FLAG(FLAG_N);
  RESET_FLAG(FLAG_C);
}

void		inst_XOR(t_parameter *param)
{
  uint8_t	result;

  result = get_param_value(param) ^ get_param_value(param + 1);
  set_param_value(param, result);
  CONDITION_FLAG(FLAG_Z, result == 0);
  RESET_FLAG(FLAG_N);
  RESET_FLAG(FLAG_C);
}

void	inst_INC(t_parameter *param)
{
  set_param_value(param, get_param_value(param) + 1);
  if (IS_8_PARAM(param))
    {
      CONDITION_FLAG(FLAG_Z, get_param_value(param) == 0);
      RESET_FLAG(FLAG_N);
    }
}

void	inst_DEC(t_parameter *param)
{
  set_param_value(param, get_param_value(param) - 1);
  if (IS_8_PARAM(param))
    {
      CONDITION_FLAG(FLAG_Z, get_param_value(param) == 0);
      SET_FLAG(FLAG_N);
    }
}

void		inst_CP(t_parameter *param)
{
  uint8_t	a;
  uint8_t	b;

  a = get_param_value(param);
  b = get_param_value(param + 1);
  CONDITION_FLAG(FLAG_Z, a == b);
  SET_FLAG(FLAG_N);
  CONDITION_FLAG(FLAG_C, a < b);
}
