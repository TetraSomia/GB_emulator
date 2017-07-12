/*
** cb_prefix.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jul 12 19:55:12 2017 Arthur Josso
** Last update Wed Jul 12 20:11:02 2017 Arthur Josso
*/

#include "opcode.h"
#include "cb_opcode.h"

static void	cb_swap(t_cb_byte op_code)
{
  (void)op_code;
}

static void	cb_shift(t_cb_byte op_code)
{
  (void)op_code;
}

static void	cb_bit(t_cb_byte op_code)
{
  (void)op_code;
}

static void	cb_reset(t_cb_byte op_code)
{
  (void)op_code;
}

static void	cb_set(t_cb_byte op_code)
{
  (void)op_code;
}

static const t_cb_func_desc	cb_ops[] =
  {
    {0b00, 0b110, cb_swap},
    {0b00, Y_NOT_MANDATORY, cb_shift},
    {0b01, Y_NOT_MANDATORY, cb_bit},
    {0b10, Y_NOT_MANDATORY, cb_reset},
    {0b11, Y_NOT_MANDATORY, cb_set},
  };

void		inst_CB_prefix(t_parameter *param)
{
  t_cb_byte	op_code;
  int		i;

  op_code.raw = get_param_value(param);
  i = 0;
  while (1)
    {
      if (cb_ops[i].x == op_code.x &&
	  (cb_ops[i].y == Y_NOT_MANDATORY || cb_ops[i].y == op_code.y))
	{
	  cb_ops[i].op(op_code);
	  break;
	}
      i++;
    }
}
