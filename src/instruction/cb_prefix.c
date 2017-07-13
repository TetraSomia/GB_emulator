/*
** cb_prefix.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jul 12 19:55:12 2017 Arthur Josso
** Last update Thu Jul 13 18:51:06 2017 Arthur Josso
*/

#include "memory.h"
#include "opcode.h"
#include "cb_opcode.h"
#include "misc.h"

static void	cb_shift(uint8_t type, t_parameter *concerned_reg)
{
  uint8_t	tmp;
  uint8_t	carry_save;
  t_cb_shift_op	op_type;

  tmp = get_param_value(concerned_reg);
  carry_save = GET_FLAG(FLAG_C);
  op_type = type;
  switch (op_type)
    {
    case CB_RLC:
      CONDITION_FLAG(FLAG_C, tmp >> 7);
      tmp = (tmp << 1) | carry_save;
      break;
    case CB_RRC:
      CONDITION_FLAG(FLAG_C, tmp & 1);
      tmp = (tmp >> 1) | (carry_save << 7);
      break;
    case CB_RL:
      CONDITION_FLAG(FLAG_C, tmp >> 7);
      tmp = (tmp << 1) | (tmp >> 7);
      break;
    case CB_RR:
      CONDITION_FLAG(FLAG_C, tmp & 1);
      tmp = (tmp >> 1) | (tmp << 7);
      break;
    case CB_SLA:
      CONDITION_FLAG(FLAG_C, tmp >> 7);
      tmp <<= 1;
      break;
    case CB_SRA:
      CONDITION_FLAG(FLAG_C, tmp & 1);
      tmp = (tmp >> 1) | (tmp & (1 << 7));
      break;
    case CB_SWAP:
      emu_warn("cb_shift", "Malformed opcode");
      break;
    case CB_SRL:
      CONDITION_FLAG(FLAG_C, tmp & 1);
      tmp >>= 1;
      break;
    };
  set_param_value(concerned_reg, tmp);
  CONDITION_FLAG(FLAG_Z, tmp == 0);
  RESET_FLAG(FLAG_N);
}

static void	cb_swap(uint8_t swap_specifier, t_parameter *concerned_reg)
{
  uint8_t	tmp;

  (void)swap_specifier;
  tmp = get_param_value(concerned_reg);
  tmp = (tmp << 4) | (tmp >> 4);
  set_param_value(concerned_reg, tmp);
  CONDITION_FLAG(FLAG_Z, tmp == 0);
  RESET_FLAG(FLAG_N);
  RESET_FLAG(FLAG_C);
}

static void	cb_bit(uint8_t bit, t_parameter *concerned_reg)
{
  uint8_t	tmp;

  tmp = get_param_value(concerned_reg);
  CONDITION_FLAG(FLAG_Z, ((tmp >> bit) & 1) == 0);
  RESET_FLAG(FLAG_N);
}

static void	cb_reset(uint8_t bit, t_parameter *concerned_reg)
{
  uint8_t	tmp;

  tmp =	get_param_value(concerned_reg);
  tmp &= ~(1 << bit);
  set_param_value(concerned_reg, tmp);
}

static void	cb_set(uint8_t bit, t_parameter *concerned_reg)
{
  uint8_t	tmp;

  tmp = get_param_value(concerned_reg);
  tmp |= 1 << bit;
  set_param_value(concerned_reg, tmp);
}

static const t_cb_func_desc	cb_ops[] =
  {
    {0b00, 0b110, cb_swap},
    {0b00, Y_NOT_MANDATORY, cb_shift},
    {0b01, Y_NOT_MANDATORY, cb_bit},
    {0b10, Y_NOT_MANDATORY, cb_reset},
    {0b11, Y_NOT_MANDATORY, cb_set},
  };

static t_parameter regs_by_id[] =
  {
    P_REG_8(B),
    P_REG_8(C),
    P_REG_8(D),
    P_REG_8(E),
    P_REG_8(H),
    P_REG_8(L),
    P_IREG_8(HL),
    P_REG_8(A),
  };

void		inst_CB_prefix(t_parameter *param)
{
  t_cb_byte	op_code;
  t_parameter	*concerned_reg;
  int		i;

  op_code.raw = get_param_value(param);
  concerned_reg = &regs_by_id[op_code.z];
  i = 0;
  while (1)
    {
      if (cb_ops[i].x == op_code.x &&
	  (cb_ops[i].y == Y_NOT_MANDATORY || cb_ops[i].y == op_code.y))
	{
	  cb_ops[i].op(op_code.y, concerned_reg);
	  break;
	}
      i++;
    }
  // add_clock_cycles(concerned_reg->type == IREG_8 ? 4 : 2);
}
