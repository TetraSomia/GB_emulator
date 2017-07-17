/*
** core.h for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Tue Jul 18 00:30:10 2017 Arthur Josso
** Last update Tue Jul 18 00:50:52 2017 Arthur Josso
*/

#pragma once

#include "memory.h"

bool	dump_file(const char *path);

bool	emu_run();

void	emu_add_clock_cycles(uint8_t nbr);
