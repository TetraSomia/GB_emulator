/*
** core.h for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jul 18 00:30:10 2017 Arthur Josso
** Last update Wed Jul 26 16:52:40 2017 Arthur Josso
*/

#pragma once

#include "memory.h"

/*
** Init
*/

bool dump_file(const char *path);

/*
** Core
*/

bool emu_run();
void refresh_clock_dependent_regs(uint8_t last_opcode,
				  uint8_t cycles_duration);
