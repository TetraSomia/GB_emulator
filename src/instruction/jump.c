/*
** jump.c for gb in /home/tetra/GB
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Jul 16 22:12:28 2017 Arthur Josso
** Last update Wed Jul 26 04:17:21 2017 Arthur Josso
*/

#include "opcode.h"
#include "memory.h"
#include "instruction.h"
#include <stdio.h>
void    inst_JP(t_parameter *param)
{
  if (!is_inst_exec_on_condition(get_param_value(param + 1)))
    return;
  reg.PC = get_param_value(param);
}

void    inst_JR(t_parameter *param)
{
  if (!is_inst_exec_on_condition(get_param_value(param + 1)))
    return;
  reg.PC += (int8_t)get_param_value(param);
}

void		inst_CALL(t_parameter *param)
{
  t_parameter	push_params[2] = {P_IREG_16(SP), P_RAW(reg.PC + 3)};

  if (!is_inst_exec_on_condition(get_param_value(param + 1)))
    return;
  inst_PUSH(push_params);
  inst_JP(param);
}

void		inst_RST(t_parameter *param)
{
  t_parameter	push_params[2] = {P_IREG_16(SP), P_RAW(reg.PC + 1)};

  inst_PUSH(push_params);
  inst_JP(param);
}

void		inst_RET(t_parameter *param)
{
  t_parameter	tmp_params[2] = {P_RAW(0), param[0]};

  inst_POP(tmp_params);
  tmp_params[1] = param[1];
  inst_JP(tmp_params);
}

void	inst_RETI(t_parameter *param)
{
  inst_RET(param);
  inst_EI(NULL);
}
