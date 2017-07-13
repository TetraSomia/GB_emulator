/*
** shift.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jul 13 20:40:29 2017 Arthur Josso
** Last update Thu Jul 13 20:52:16 2017 Arthur Josso
*/

#include "opcode.h"
#include "memory.h"

void		inst_RLC(t_parameter *param)
{
  uint8_t	tmp;
  uint8_t	carry_save;

  tmp = get_param_value(param);
  carry_save = GET_FLAG(FLAG_C);
  CONDITION_FLAG(FLAG_C, tmp >> 7);
  tmp = (tmp << 1) | carry_save;
  set_param_value(param, tmp);
  CONDITION_FLAG(FLAG_Z, tmp == 0);
  RESET_FLAG(FLAG_N);
}

void            inst_RRC(t_parameter *param)
{
  uint8_t       tmp;
  uint8_t       carry_save;

  tmp = get_param_value(param);
  carry_save = GET_FLAG(FLAG_C);
  CONDITION_FLAG(FLAG_C, tmp & 1);
  tmp = (tmp >> 1) | (carry_save << 7);
  set_param_value(param, tmp);
  CONDITION_FLAG(FLAG_Z, tmp == 0);
  RESET_FLAG(FLAG_N);
}

void            inst_RL(t_parameter *param)
{
  uint8_t       tmp;

  tmp = get_param_value(param);
  CONDITION_FLAG(FLAG_C, tmp >> 7);
  tmp = (tmp << 1) | (tmp >> 7);
  set_param_value(param, tmp);
  CONDITION_FLAG(FLAG_Z, tmp == 0);
  RESET_FLAG(FLAG_N);
}

void            inst_RR(t_parameter *param)
{
  uint8_t       tmp;

  tmp = get_param_value(param);
  CONDITION_FLAG(FLAG_C, tmp & 1);
  tmp = (tmp >> 1) | (tmp << 7);
  set_param_value(param, tmp);
  CONDITION_FLAG(FLAG_Z, tmp == 0);
  RESET_FLAG(FLAG_N);
}

void            inst_SLA(t_parameter *param)
{
  uint8_t       tmp;

  tmp = get_param_value(param);
  CONDITION_FLAG(FLAG_C, tmp >> 7);
  tmp <<= 1;
  set_param_value(param, tmp);
  CONDITION_FLAG(FLAG_Z, tmp == 0);
  RESET_FLAG(FLAG_N);
}

void            inst_SRA(t_parameter *param)
{
  uint8_t       tmp;

  tmp = get_param_value(param);
  CONDITION_FLAG(FLAG_C, tmp & 1);
  tmp = (tmp >> 1) | (tmp & (1 << 7));
  set_param_value(param, tmp);
  CONDITION_FLAG(FLAG_Z, tmp == 0);
  RESET_FLAG(FLAG_N);
}

void            inst_SRL(t_parameter *param)
{
  uint8_t       tmp;

  tmp = get_param_value(param);
  CONDITION_FLAG(FLAG_C, tmp & 1);
  tmp >>= 1;
  set_param_value(param, tmp);
  CONDITION_FLAG(FLAG_Z, tmp == 0);
  RESET_FLAG(FLAG_N);
}
