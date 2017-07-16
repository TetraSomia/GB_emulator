/*
** instruction.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Mar 11 19:42:14 2017 Arthur Josso
** Last update Sun Jul 16 23:18:33 2017 Arthur Josso
*/

#include "opcode.h"
#include "memory.h"

void    inst_PUSH(t_parameter *param)
{
  reg.SP -= 2;
  set_param_value(param, get_param_value(param + 1));
}

void    inst_POP(t_parameter *param)
{
  set_param_value(param, get_param_value(param + 1));
  reg.SP += 2;
}
