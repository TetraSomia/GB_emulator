/*
** param_op.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Jul  9 21:32:15 2017 Arthur Josso
** Last update Tue Jul 18 01:38:05 2017 Arthur Josso
*/

#include "opcode.h"
#include "memory.h"
#include "misc.h"

void	set_param_value(t_parameter *param, uint16_t value)
{
  switch (param->type)
    {
    case REG_8:
      *(uint8_t*)(param->addr) = value;
      break;
    case REG_16:
      *(uint16_t*)(param->addr) = value;
      break;
    case IREG_8:
      set_byte(*(uint16_t*)(param->addr), value);
      break;
    case IREG_16:
      set_word(*(uint16_t*)(param->addr), value);
      break;
    case VAL_8:
      set_byte(reg.PC + 1, value);
      break;
    case VAL_16:
      set_word(reg.PC + 1, value);
      break;
    case IVAL_8:
      set_byte(get_word(reg.PC + 1), value);
      break;
    case IVAL_16:
      set_word(get_word(reg.PC + 1), value);
      break;
    case RAW:
      param->raw = value;
      break;
    default:
      emu_warn("set_param_value", "Unknown parameter type");
      break;
    }
}

uint16_t	get_param_value(t_parameter *param)
{
  switch (param->type)
    {
    case REG_8:
      return (*(uint8_t*)(param->addr));
    case REG_16:
      return (*(uint16_t*)(param->addr));
    case IREG_8:
      return (get_byte(*(uint16_t*)(param->addr)));
    case IREG_16:
      return (get_word(*(uint16_t*)(param->addr)));
    case VAL_8:
      return (get_byte(reg.PC + 1));
    case VAL_16:
      return (get_word(reg.PC + 1));
    case IVAL_8:
      return (get_byte(get_word(reg.PC + 1)));
    case IVAL_16:
      return (get_word(get_word(reg.PC + 1)));
    case RAW:
      return (param->raw);
    default:
      emu_warn("get_param_value", "Unknown parameter type");
      return (0);
    }
}
