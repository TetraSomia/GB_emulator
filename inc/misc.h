/*
** misc.h for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sun Mar  5 18:14:58 2017 Arthur Josso
** Last update Sun Jul  9 21:37:19 2017 Arthur Josso
*/

#pragma once

#include <stddef.h>

void    *xalloc(size_t size);

void	emu_warn(const char *func, const char *msg);
