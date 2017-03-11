/*
** instruction.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Mar 11 19:42:14 2017 Arthur Josso
** Last update Sun Mar 12 00:19:54 2017 Arthur Josso
*/

#include "opcode.h"
#include "memory.h"

void	inst_LD(t_parameter *param)
{
  set_param_value(param + 1, get_param_value(param));
}
