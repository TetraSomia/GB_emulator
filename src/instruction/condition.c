/*
** condition.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Jul 16 22:21:11 2017 Arthur Josso
** Last update Sun Jul 16 22:26:57 2017 Arthur Josso
*/

#include "memory.h"
#include "opcode.h"
#include "misc.h"

bool	is_inst_exec_on_condition(t_inst_condition cond)
{
  switch (cond)
    {
    case CONDITION_NONE:
      return (true);
    case CONDITION_NZ:
      return (!GET_FLAG(FLAG_Z));
    case CONDITION_Z:
      return (GET_FLAG(FLAG_Z));
    case CONDITION_NC:
      return (!GET_FLAG(FLAG_C));
    case CONDITION_C:
      return (GET_FLAG(FLAG_C));
    default:
      emu_warn("is_inst_exec_on_condition", "Unknown condition flag");
      return (false);
    }
}
