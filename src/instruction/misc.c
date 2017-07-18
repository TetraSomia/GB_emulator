/*
** misc.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Thu Jul 13 20:03:27 2017 Arthur Josso
** Last update Tue Jul 18 21:08:40 2017 Arthur Josso
*/

#include "opcode.h"
#include "memory.h"

void		inst_DAA(t_parameter *param)
{
  uint8_t	old_a;
  uint8_t	old_carry;

  old_a = get_param_value(param);
  old_carry = GET_FLAG(FLAG_C);
  RESET_FLAG(FLAG_C);
  if ((old_a & 0x0F) > 9 || GET_FLAG(FLAG_H) == 1)
    {
      set_param_value(param, old_a + 6);
      CONDITION_FLAG(FLAG_C, old_carry || IS_CARRY(old_a, 6, 8));
      // SET_FLAG(FLAG_H); if i used to use it
    }
  else
    RESET_FLAG(FLAG_H);
  if (old_a > 0x99 || old_carry)
    {
      set_param_value(param, old_a + 0x60);
      SET_FLAG(FLAG_C);
    }
  else
    RESET_FLAG(FLAG_C);
  CONDITION_FLAG(FLAG_Z, get_param_value(param) == 0);
}

void	inst_CPL(t_parameter *param)
{
  set_param_value(param, ~get_param_value(param));
  SET_FLAG(FLAG_N);
}

void	inst_CCF(t_parameter *param)
{
  (void)param;
  CONDITION_FLAG(FLAG_C, !GET_FLAG(FLAG_C));
  RESET_FLAG(FLAG_N);
}

void	inst_SCF(t_parameter *param)
{
  (void)param;
  SET_FLAG(FLAG_C);
  RESET_FLAG(FLAG_N);
}

void	inst_NOP(t_parameter *param)
{
  (void)param;
}

void	inst_HALT(t_parameter *param)
{
  (void)param;
  if (GET_FLAG(FLAG_I))
    (void)param; //stop execution and wait for interruption
  else
    reg.PC++;
}

void	inst_EI(t_parameter *param)
{
  (void)param;
  SET_FLAG(FLAG_I);
}

void	inst_DI(t_parameter *param)
{
  (void)param;
  RESET_FLAG(FLAG_I);
}
