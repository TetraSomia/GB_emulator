/*
** cb_prefix.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jul 12 19:55:12 2017 Arthur Josso
** Last update Mon Jul 24 00:00:37 2017 Arthur Josso
*/

#include "core.h"
#include "opcode.h"
#include "cb_opcode.h"
#include "instruction.h"
#include "misc.h"

static void		cb_shift(uint8_t type, t_parameter *concerned_reg)
{
  const t_op_func	rot_funcs[] =
  {
    inst_RLC,
    inst_RRC,
    inst_RL,
    inst_RR,
    inst_SLA,
    inst_SRA,
    NULL,
    inst_SRL
  };

  if (rot_funcs[type] == NULL)
    emu_warn("cb_shift", "Malformed opcode");
  else
    rot_funcs[type](concerned_reg);
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

static uint8_t	cb_inst_cycles = 0;

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
  cb_inst_cycles = concerned_reg->type == IREG_8 ? 4 : 2;
}

uint8_t	get_last_cb_inst_cycles()
{
  return (cb_inst_cycles);
}
