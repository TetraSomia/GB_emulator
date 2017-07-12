/*
** cb_prefix.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jul 12 19:55:12 2017 Arthur Josso
** Last update Wed Jul 12 21:23:47 2017 Arthur Josso
*/

#include "memory.h"
#include "opcode.h"
#include "cb_opcode.h"

static void	cb_swap(t_cb_byte op_code, t_parameter *concerned_reg)
{
  uint8_t	tmp;

  (void)op_code;
  tmp = get_param_value(concerned_reg);
  tmp = (tmp << 4) | (tmp >> 4);
  set_param_value(concerned_reg, tmp);
}

static void	cb_shift(t_cb_byte op_code, t_parameter *concerned_reg)
{
  (void)op_code;
  (void)concerned_reg;
}

static void	cb_bit(t_cb_byte op_code, t_parameter *concerned_reg)
{
  (void)op_code;
  (void)concerned_reg;
}

static void	cb_reset(t_cb_byte op_code, t_parameter *concerned_reg)
{
  (void)op_code;
  (void)concerned_reg;
}

static void	cb_set(t_cb_byte op_code, t_parameter *concerned_reg)
{
  (void)op_code;
  (void)concerned_reg;
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
	  cb_ops[i].op(op_code, concerned_reg);
	  break;
	}
      i++;
    }
  // add_clock_cycles(concerned_reg->type == IREG_8 ? 4 : 2);
}
