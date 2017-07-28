/*
** refresh.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Mon Jul 24 23:15:48 2017 Arthur Josso
** Last update Fri Jul 28 19:00:41 2017 Arthur Josso
*/

#include "memory.h"
#include "screen.h"
#include "special_reg.h"

static t_screen_state	define_screen_state(uint32_t clock)
{
  static const uint32_t	state_durations[SCR_STATE_NBR] =
    {
      51,
      1140,
      20,
      43
    };

  if (clock >= SCR_REFRESH_DUR_WITHOUT_VB)
    return (SCR_VBLANK);
  clock /= SCR_NBR_LINES;
  if (clock < state_durations[SCR_HBLANK])
    return (SCR_HBLANK);
  if (clock < state_durations[SCR_HBLANK]
      + state_durations[SCR_OAM_SEARCH])
    return (SCR_OAM_SEARCH);
  return (SCR_DATA_TRANSFER);
}

void			refresh_screen_state(uint8_t elapsed_cycles)
{
  t_spereg_stat * const	stat_reg = (void*)&mem->raw[REG_STAT];
  t_screen_state	new_state;

  if (!GET_BIT(mem->raw[REG_LCDC], 7))
    return;
  screen.clock = (screen.clock + elapsed_cycles) % SCR_COMPLETE_REFRESH_DUR;
  new_state = define_screen_state(screen.clock);
  screen.changed_state = screen.state == new_state ? false : true;
  screen.state = new_state;
  screen.line = screen.clock / SCR_LINE_REFRESH_DUR;
  mem->raw[REG_LY] = screen.line;
  stat_reg->state = screen.state;
  stat_reg->coincidence = screen.line == mem->raw[REG_LYC] ? 1 : 0;
}

void    screen_check_for_update()
{
  if (!screen.changed_state)
    return;
  if (screen.state == SCR_DATA_TRANSFER && screen.line < SCR_NBR_LINES)
    screen_draw_line(screen.line);
  else if (screen.state == SCR_HBLANK && screen.line == 0)
    {
      screen_blit();
      screen_draw_background();
    }
}
