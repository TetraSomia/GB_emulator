/*
** jump.c for gb in /home/tetra/GB
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Jul 16 22:12:28 2017 Arthur Josso
** Last update Sun Jul 16 22:38:08 2017 Arthur Josso
*/

#include "opcode.h"
#include "memory.h"

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
