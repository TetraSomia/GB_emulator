/*
** refresh.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jul 24 23:15:48 2017 Arthur Josso
** Last update Tue Jul 25 00:46:04 2017 Arthur Josso
*/

#include "memory.h"
#include "screen.h"
#include "special_reg.h"

static t_screen_state	define_screen_state(uint32_t clock)
{
  static const uint32_t	state_durations[SCR_STATE_NBR] =
    {
      204,
      4560,
      80,
      172
    };

  if (clock >= SCR_REFRESH_DUR_WITHOUT_VB)
    return (SCR_VBLANK);
  clock /= SCR_NBR_LINES;
  if (clock < state_durations[SCR_HBLANK])
    return (SCR_HBLANK);
  if (clock < state_durations[SCR_HBLANK] +
      state_durations[SCR_OAM_SEARCH])
    return (SCR_OAM_SEARCH);
  return (SCR_DATA_TRANSFER);
}

void			refresh_screen_state(uint8_t elapsed_cycles)
{
  static t_screen_data	scr = {.clock = 0, .state = SCR_HBLANK};
  t_spereg_stat * const	stat_reg = (void*)&mem->raw[REG_STAT];

  if ((mem->raw[REG_LCDC] & (1 << 7)) == 0)
    return;
  scr.clock = (scr.clock + elapsed_cycles) % SCR_COMPLETE_REFRESH_DUR;
  scr.state = define_screen_state(scr.clock);
  scr.line = scr.clock / SCR_LINE_REFRESH_DUR;
  mem->raw[REG_LY] = scr.line;
  stat_reg->state = scr.state;
  stat_reg->coincidence = scr.line == mem->raw[REG_LYC] ? 1 : 0;
}
