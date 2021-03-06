/*
** opcode.c for gb in /home/tetra/en_cours/GB_emulator
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Sat Mar 11 19:43:47 2017 Arthur Josso
** Last update Wed Jul 26 04:15:54 2017 Arthur Josso
*/

#include "memory.h"
#include "instruction.h"
#include "opcode.h"
#include "misc.h"

static const t_instruction	inst_tab[] =
  {
    // LD

    {0x3E, 2, 2, {P_REG_8(A), P_VAL_8}, inst_LD, "LD A, n"},
    {0x06, 2, 2, {P_REG_8(B), P_VAL_8}, inst_LD, "LD B, n"},
    {0x0E, 2, 2, {P_REG_8(C), P_VAL_8}, inst_LD, "LD C, n"},
    {0x16, 2, 2, {P_REG_8(D), P_VAL_8}, inst_LD, "LD D, n"},
    {0x1E, 2, 2, {P_REG_8(E), P_VAL_8}, inst_LD, "LD E, n"},
    {0x26, 2, 2, {P_REG_8(H), P_VAL_8}, inst_LD, "LD H, n"},
    {0x2E, 2, 2, {P_REG_8(L), P_VAL_8}, inst_LD, "LD L, n"},

    {0x7F, 1, 1, {P_REG_8(A), P_REG_8(A)}, inst_LD, "LD A, A"},
    {0x78, 1, 1, {P_REG_8(A), P_REG_8(B)}, inst_LD, "LD A, B"},
    {0x79, 1, 1, {P_REG_8(A), P_REG_8(C)}, inst_LD, "LD A, C"},
    {0x7A, 1, 1, {P_REG_8(A), P_REG_8(D)}, inst_LD, "LD A, D"},
    {0x7B, 1, 1, {P_REG_8(A), P_REG_8(E)}, inst_LD, "LD A, E"},
    {0x7C, 1, 1, {P_REG_8(A), P_REG_8(H)}, inst_LD, "LD A, H"},
    {0x7D, 1, 1, {P_REG_8(A), P_REG_8(L)}, inst_LD, "LD A, L"},
    {0x7E, 2, 1, {P_REG_8(A), P_IREG_8(HL)}, inst_LD, "LD A, (HL)"},

    {0x47, 1, 1, {P_REG_8(B), P_REG_8(A)}, inst_LD, "LD B, A"},
    {0x40, 1, 1, {P_REG_8(B), P_REG_8(B)}, inst_LD, "LD B, B"},
    {0x41, 1, 1, {P_REG_8(B), P_REG_8(C)}, inst_LD, "LD B, C"},
    {0x42, 1, 1, {P_REG_8(B), P_REG_8(D)}, inst_LD, "LD B, D"},
    {0x43, 1, 1, {P_REG_8(B), P_REG_8(E)}, inst_LD, "LD B, E"},
    {0x44, 1, 1, {P_REG_8(B), P_REG_8(H)}, inst_LD, "LD B, H"},
    {0x45, 1, 1, {P_REG_8(B), P_REG_8(L)}, inst_LD, "LD B, L"},
    {0x46, 2, 1, {P_REG_8(B), P_IREG_8(HL)}, inst_LD, "LD B, (HL)"},

    {0x4F, 1, 1, {P_REG_8(C), P_REG_8(A)}, inst_LD, "LD C, A"},
    {0x48, 1, 1, {P_REG_8(C), P_REG_8(B)}, inst_LD, "LD C, B"},
    {0x49, 1, 1, {P_REG_8(C), P_REG_8(C)}, inst_LD, "LD C, C"},
    {0x4A, 1, 1, {P_REG_8(C), P_REG_8(D)}, inst_LD, "LD C, D"},
    {0x4B, 1, 1, {P_REG_8(C), P_REG_8(E)}, inst_LD, "LD C, E"},
    {0x4C, 1, 1, {P_REG_8(C), P_REG_8(H)}, inst_LD, "LD C, H"},
    {0x4D, 1, 1, {P_REG_8(C), P_REG_8(L)}, inst_LD, "LD C, L"},
    {0x4E, 2, 1, {P_REG_8(C), P_IREG_8(HL)}, inst_LD, "LD C, (HL)"},

    {0x57, 1, 1, {P_REG_8(D), P_REG_8(A)}, inst_LD, "LD D, A"},
    {0x50, 1, 1, {P_REG_8(D), P_REG_8(B)}, inst_LD, "LD D, B"},
    {0x51, 1, 1, {P_REG_8(D), P_REG_8(C)}, inst_LD, "LD D, C"},
    {0x52, 1, 1, {P_REG_8(D), P_REG_8(D)}, inst_LD, "LD D, D"},
    {0x53, 1, 1, {P_REG_8(D), P_REG_8(E)}, inst_LD, "LD D, E"},
    {0x54, 1, 1, {P_REG_8(D), P_REG_8(H)}, inst_LD, "LD D, H"},
    {0x55, 1, 1, {P_REG_8(D), P_REG_8(L)}, inst_LD, "LD D, L"},
    {0x56, 2, 1, {P_REG_8(D), P_IREG_8(HL)}, inst_LD, "LD D, (HL)"},

    {0x5F, 1, 1, {P_REG_8(E), P_REG_8(A)}, inst_LD, "LD E, A"},
    {0x58, 1, 1, {P_REG_8(E), P_REG_8(B)}, inst_LD, "LD E, B"},
    {0x59, 1, 1, {P_REG_8(E), P_REG_8(C)}, inst_LD, "LD E, C"},
    {0x5A, 1, 1, {P_REG_8(E), P_REG_8(D)}, inst_LD, "LD E, D"},
    {0x5B, 1, 1, {P_REG_8(E), P_REG_8(E)}, inst_LD, "LD E, E"},
    {0x5C, 1, 1, {P_REG_8(E), P_REG_8(H)}, inst_LD, "LD E, H"},
    {0x5D, 1, 1, {P_REG_8(E), P_REG_8(L)}, inst_LD, "LD E, L"},
    {0x5E, 2, 1, {P_REG_8(E), P_IREG_8(HL)}, inst_LD, "LD E, (HL)"},

    {0x67, 1, 1, {P_REG_8(H), P_REG_8(A)}, inst_LD, "LD H, A"},
    {0x60, 1, 1, {P_REG_8(H), P_REG_8(B)}, inst_LD, "LD H, B"},
    {0x61, 1, 1, {P_REG_8(H), P_REG_8(C)}, inst_LD, "LD H, C"},
    {0x62, 1, 1, {P_REG_8(H), P_REG_8(D)}, inst_LD, "LD H, D"},
    {0x63, 1, 1, {P_REG_8(H), P_REG_8(E)}, inst_LD, "LD H, E"},
    {0x64, 1, 1, {P_REG_8(H), P_REG_8(H)}, inst_LD, "LD H, H"},
    {0x65, 1, 1, {P_REG_8(H), P_REG_8(L)}, inst_LD, "LD H, L"},
    {0x66, 2, 1, {P_REG_8(H), P_IREG_8(HL)}, inst_LD, "LD H, (HL)"},

    {0x6F, 1, 1, {P_REG_8(L), P_REG_8(A)}, inst_LD, "LD L, A"},
    {0x68, 1, 1, {P_REG_8(L), P_REG_8(B)}, inst_LD, "LD L, B"},
    {0x69, 1, 1, {P_REG_8(L), P_REG_8(C)}, inst_LD, "LD L, C"},
    {0x6A, 1, 1, {P_REG_8(L), P_REG_8(D)}, inst_LD, "LD L, D"},
    {0x6B, 1, 1, {P_REG_8(L), P_REG_8(E)}, inst_LD, "LD L, E"},
    {0x6C, 1, 1, {P_REG_8(L), P_REG_8(H)}, inst_LD, "LD L, H"},
    {0x6D, 1, 1, {P_REG_8(L), P_REG_8(L)}, inst_LD, "LD L, L"},
    {0x6E, 2, 1, {P_REG_8(L), P_IREG_8(HL)}, inst_LD, "LD L, (HL)"},

    {0x70, 2, 1, {P_IREG_8(HL), P_REG_8(B)}, inst_LD, "LD (HL), B"},
    {0x71, 2, 1, {P_IREG_8(HL), P_REG_8(C)}, inst_LD, "LD (HL), C"},
    {0x72, 2, 1, {P_IREG_8(HL), P_REG_8(D)}, inst_LD, "LD (HL), D"},
    {0x73, 2, 1, {P_IREG_8(HL), P_REG_8(E)}, inst_LD, "LD (HL), E"},
    {0x74, 2, 1, {P_IREG_8(HL), P_REG_8(H)}, inst_LD, "LD (HL), H"},
    {0x75, 2, 1, {P_IREG_8(HL), P_REG_8(L)}, inst_LD, "LD (HL), L"},
    {0x36, 3, 2, {P_IREG_8(HL), P_VAL_8}, inst_LD, "LD (HL), n"},

    {0x0A, 2, 1, {P_REG_8(A), P_IREG_8(BC)}, inst_LD, "LD A, (BC)"},
    {0x1A, 2, 1, {P_REG_8(A), P_IREG_8(DE)}, inst_LD, "LD A, (DE)"},
    {0xFA, 4, 3, {P_REG_8(A), P_IVAL_8}, inst_LD, "LD A, (nn)"},
    {0x02, 2, 1, {P_IREG_8(BC), P_REG_8(A)}, inst_LD, "LD (BC), A"},
    {0x12, 2, 1, {P_IREG_8(DE), P_REG_8(A)}, inst_LD, "LD (DE), A"},
    {0x77, 2, 1, {P_IREG_8(HL), P_REG_8(A)}, inst_LD, "LD (HL), A"},
    {0xEA, 4, 3, {P_IVAL_8, P_REG_8(A)}, inst_LD, "LD (nn), A"},

    // LD + offset

    {0xF2, 2, 1, {P_REG_8(A), P_REG_8(C)}, inst_LDH, "LD A, ($FF00 + C)"},
    {0xE2, 2, 1, {P_REG_8(C), P_REG_8(A)}, inst_LDH, "LD ($FF00 + C), A"},
    {0xF0, 3, 2, {P_REG_8(A), P_VAL_8}, inst_LDH, "LD A, ($FF00 + n)"},
    {0xE0, 3, 2, {P_VAL_8, P_REG_8(A)}, inst_LDH, "LD ($FF00 + n), A"},

    // LD + inc or dec

    {0x3A, 2, 1, {P_REG_8(A), P_IREG_8(HL)}, inst_LDD, "LDD A, (HL)"},
    {0x32, 2, 1, {P_IREG_8(HL), P_REG_8(A)}, inst_LDD, "LDD (HL), A"},
    {0x2A, 2, 1, {P_REG_8(A), P_IREG_8(HL)}, inst_LDI, "LDI A, (HL)"},
    {0x22, 2, 1, {P_IREG_8(HL), P_REG_8(A)}, inst_LDI, "LDI (HL), A"},

    // LD 16 bits

    {0x01, 3, 3, {P_REG_16(BC), P_VAL_16}, inst_LD, "LD BC, nn"},
    {0x11, 3, 3, {P_REG_16(DE), P_VAL_16}, inst_LD, "LD DE, nn"},
    {0x21, 3, 3, {P_REG_16(HL), P_VAL_16}, inst_LD, "LD HL, nn"},
    {0x31, 3, 3, {P_REG_16(SP), P_VAL_16}, inst_LD, "LD SP, nn"},

    {0xF9, 2, 1, {P_REG_16(SP), P_REG_16(HL)}, inst_LD, "LD SP, HL"},

    {0x08, 5, 3, {P_IVAL_16, P_REG_16(SP)}, inst_LD, "LD (nn), SP"},

    {0xF8, 3, 2, {P_REG_16(SP), P_VAL_8}, inst_LDHL, "LDHL SP, n"},

    // PUSH and POP

    {0xF5, 4, 1, {P_IREG_16(SP), P_REG_16(AF)}, inst_PUSH, "PUSH AF"},
    {0xC5, 4, 1, {P_IREG_16(SP), P_REG_16(BC)}, inst_PUSH, "PUSH BC"},
    {0xD5, 4, 1, {P_IREG_16(SP), P_REG_16(DE)}, inst_PUSH, "PUSH DE"},
    {0xE5, 4, 1, {P_IREG_16(SP), P_REG_16(HL)}, inst_PUSH, "PUSH HL"},

    {0xF1, 3, 1, {P_REG_16(AF), P_IREG_16(SP)}, inst_POP, "POP AF"},
    {0xC1, 3, 1, {P_REG_16(BC), P_IREG_16(SP)}, inst_POP, "POP BC"},
    {0xD1, 3, 1, {P_REG_16(DE), P_IREG_16(SP)}, inst_POP, "POP DE"},
    {0xE1, 3, 1, {P_REG_16(HL), P_IREG_16(SP)}, inst_POP, "POP HL"},

    // ALU : ADD

    {0x87, 1, 1, {P_REG_8(A), P_REG_8(A)}, inst_ADD, "ADD A, A"},
    {0x80, 1, 1, {P_REG_8(A), P_REG_8(B)}, inst_ADD, "ADD A, B"},
    {0x81, 1, 1, {P_REG_8(A), P_REG_8(C)}, inst_ADD, "ADD A, C"},
    {0x82, 1, 1, {P_REG_8(A), P_REG_8(D)}, inst_ADD, "ADD A, D"},
    {0x83, 1, 1, {P_REG_8(A), P_REG_8(E)}, inst_ADD, "ADD A, E"},
    {0x84, 1, 1, {P_REG_8(A), P_REG_8(H)}, inst_ADD, "ADD A, H"},
    {0x85, 1, 1, {P_REG_8(A), P_REG_8(L)}, inst_ADD, "ADD A, L"},
    {0x86, 2, 1, {P_REG_8(A), P_IREG_8(HL)}, inst_ADD, "ADD A, (HL)"},
    {0xC6, 2, 2, {P_REG_8(A), P_VAL_8}, inst_ADD, "ADD A, #"},

    {0x09, 2, 1, {P_REG_16(HL), P_REG_16(BC)}, inst_ADD, "ADD HL, BC"},
    {0x19, 2, 1, {P_REG_16(HL), P_REG_16(DE)}, inst_ADD, "ADD HL, DE"},
    {0x29, 2, 1, {P_REG_16(HL), P_REG_16(HL)}, inst_ADD, "ADD HL, HL"},
    {0x39, 2, 1, {P_REG_16(HL), P_REG_16(SP)}, inst_ADD, "ADD HL, SP"},

    {0xE8, 4, 2, {P_REG_16(SP), P_VAL_8}, inst_ADD_SP, "ADD SP, #"},

    {0x8F, 1, 1, {P_REG_8(A), P_REG_8(A)}, inst_ADC, "ADC A, A"},
    {0x88, 1, 1, {P_REG_8(A), P_REG_8(B)}, inst_ADC, "ADC A, B"},
    {0x89, 1, 1, {P_REG_8(A), P_REG_8(C)}, inst_ADC, "ADC A, C"},
    {0x8A, 1, 1, {P_REG_8(A), P_REG_8(D)}, inst_ADC, "ADC A, D"},
    {0x8B, 1, 1, {P_REG_8(A), P_REG_8(E)}, inst_ADC, "ADC A, E"},
    {0x8C, 1, 1, {P_REG_8(A), P_REG_8(H)}, inst_ADC, "ADC A, H"},
    {0x8D, 1, 1, {P_REG_8(A), P_REG_8(L)}, inst_ADC, "ADC A, L"},
    {0x8E, 2, 1, {P_REG_8(A), P_IREG_8(HL)}, inst_ADC, "ADC A, (HL)"},
    {0xCE, 2, 2, {P_REG_8(A), P_VAL_8}, inst_ADC, "ADC A, #"},

    // ALU : SUB

    {0x97, 1, 1, {P_REG_8(A), P_REG_8(A)}, inst_SUB, "SUB A, A"},
    {0x90, 1, 1, {P_REG_8(A), P_REG_8(B)}, inst_SUB, "SUB A, B"},
    {0x91, 1, 1, {P_REG_8(A), P_REG_8(C)}, inst_SUB, "SUB A, C"},
    {0x92, 1, 1, {P_REG_8(A), P_REG_8(D)}, inst_SUB, "SUB A, D"},
    {0x93, 1, 1, {P_REG_8(A), P_REG_8(E)}, inst_SUB, "SUB A, E"},
    {0x94, 1, 1, {P_REG_8(A), P_REG_8(H)}, inst_SUB, "SUB A, H"},
    {0x95, 1, 1, {P_REG_8(A), P_REG_8(L)}, inst_SUB, "SUB A, L"},
    {0x96, 2, 1, {P_REG_8(A), P_IREG_8(HL)}, inst_SUB, "SUB A, (HL)"},
    {0xD6, 2, 2, {P_REG_8(A), P_VAL_8}, inst_SUB, "SUB A, #"},

    {0x9F, 1, 1, {P_REG_8(A), P_REG_8(A)}, inst_SBC, "SBC A, A"},
    {0x98, 1, 1, {P_REG_8(A), P_REG_8(B)}, inst_SBC, "SBC A, B"},
    {0x99, 1, 1, {P_REG_8(A), P_REG_8(C)}, inst_SBC, "SBC A, C"},
    {0x9A, 1, 1, {P_REG_8(A), P_REG_8(D)}, inst_SBC, "SBC A, D"},
    {0x9B, 1, 1, {P_REG_8(A), P_REG_8(E)}, inst_SBC, "SBC A, E"},
    {0x9C, 1, 1, {P_REG_8(A), P_REG_8(H)}, inst_SBC, "SBC A, H"},
    {0x9D, 1, 1, {P_REG_8(A), P_REG_8(L)}, inst_SBC, "SBC A, L"},
    {0x9E, 2, 1, {P_REG_8(A), P_IREG_8(HL)}, inst_SBC, "SBC A, (HL)"},

    // ALU : Bitwise operators

    {0xA7, 1, 1, {P_REG_8(A), P_REG_8(A)}, inst_AND, "AND A, A"},
    {0xA0, 1, 1, {P_REG_8(A), P_REG_8(B)}, inst_AND, "AND A, B"},
    {0xA1, 1, 1, {P_REG_8(A), P_REG_8(C)}, inst_AND, "AND A, C"},
    {0xA2, 1, 1, {P_REG_8(A), P_REG_8(D)}, inst_AND, "AND A, D"},
    {0xA3, 1, 1, {P_REG_8(A), P_REG_8(E)}, inst_AND, "AND A, E"},
    {0xA4, 1, 1, {P_REG_8(A), P_REG_8(H)}, inst_AND, "AND A, H"},
    {0xA5, 1, 1, {P_REG_8(A), P_REG_8(L)}, inst_AND, "AND A, L"},
    {0xA6, 2, 1, {P_REG_8(A), P_IREG_8(HL)}, inst_AND, "AND A, (HL)"},
    {0xE6, 2, 2, {P_REG_8(A), P_VAL_8}, inst_AND, "AND A, #"},

    {0xB7, 1, 1, {P_REG_8(A), P_REG_8(A)}, inst_OR, "OR A, A"},
    {0xB0, 1, 1, {P_REG_8(A), P_REG_8(B)}, inst_OR, "OR A, B"},
    {0xB1, 1, 1, {P_REG_8(A), P_REG_8(C)}, inst_OR, "OR A, C"},
    {0xB2, 1, 1, {P_REG_8(A), P_REG_8(D)}, inst_OR, "OR A, D"},
    {0xB3, 1, 1, {P_REG_8(A), P_REG_8(E)}, inst_OR, "OR A, E"},
    {0xB4, 1, 1, {P_REG_8(A), P_REG_8(H)}, inst_OR, "OR A, H"},
    {0xB5, 1, 1, {P_REG_8(A), P_REG_8(L)}, inst_OR, "OR A, L"},
    {0xB6, 2, 1, {P_REG_8(A), P_IREG_8(HL)}, inst_OR, "OR A, (HL)"},
    {0xF6, 2, 2, {P_REG_8(A), P_VAL_8}, inst_OR, "OR A, #"},

    {0xAF, 1, 1, {P_REG_8(A), P_REG_8(A)}, inst_XOR, "XOR A, A"},
    {0xA8, 1, 1, {P_REG_8(A), P_REG_8(B)}, inst_XOR, "XOR A, B"},
    {0xA9, 1, 1, {P_REG_8(A), P_REG_8(C)}, inst_XOR, "XOR A, C"},
    {0xAA, 1, 1, {P_REG_8(A), P_REG_8(D)}, inst_XOR, "XOR A, D"},
    {0xAB, 1, 1, {P_REG_8(A), P_REG_8(E)}, inst_XOR, "XOR A, E"},
    {0xAC, 1, 1, {P_REG_8(A), P_REG_8(H)}, inst_XOR, "XOR A, H"},
    {0xAD, 1, 1, {P_REG_8(A), P_REG_8(L)}, inst_XOR, "XOR A, L"},
    {0xAE, 2, 1, {P_REG_8(A), P_IREG_8(HL)}, inst_XOR, "XOR A, (HL)"},
    {0xEE, 2, 2, {P_REG_8(A), P_VAL_8}, inst_XOR, "XOR A, #"},

    // ALU : Incrementation & Decrementation

    {0x3C, 1, 1, {P_REG_8(A)}, inst_INC, "INC A"},
    {0x04, 1, 1, {P_REG_8(B)}, inst_INC, "INC B"},
    {0x0C, 1, 1, {P_REG_8(C)}, inst_INC, "INC C"},
    {0x14, 1, 1, {P_REG_8(D)}, inst_INC, "INC D"},
    {0x1C, 1, 1, {P_REG_8(E)}, inst_INC, "INC E"},
    {0x24, 1, 1, {P_REG_8(H)}, inst_INC, "INC H"},
    {0x2C, 1, 1, {P_REG_8(L)}, inst_INC, "INC L"},
    {0x34, 3, 1, {P_IREG_8(HL)}, inst_INC, "INC (HL)"},

    {0x03, 2, 1, {P_REG_16(BC)}, inst_INC, "INC BC"},
    {0x13, 2, 1, {P_REG_16(DE)}, inst_INC, "INC DE"},
    {0x23, 2, 1, {P_REG_16(HL)}, inst_INC, "INC HL"},
    {0x33, 2, 1, {P_REG_16(SP)}, inst_INC, "INC SP"},

    {0x3D, 1, 1, {P_REG_8(A)}, inst_DEC, "DEC A"},
    {0x05, 1, 1, {P_REG_8(B)}, inst_DEC, "DEC B"},
    {0x0D, 1, 1, {P_REG_8(C)}, inst_DEC, "DEC C"},
    {0x15, 1, 1, {P_REG_8(D)}, inst_DEC, "DEC D"},
    {0x1D, 1, 1, {P_REG_8(E)}, inst_DEC, "DEC E"},
    {0x25, 1, 1, {P_REG_8(H)}, inst_DEC, "DEC H"},
    {0x2D, 1, 1, {P_REG_8(L)}, inst_DEC, "DEC L"},
    {0x35, 3, 1, {P_IREG_8(HL)}, inst_DEC, "DEC (HL)"},

    {0x0B, 2, 1, {P_REG_16(BC)}, inst_DEC, "DEC BC"},
    {0x1B, 2, 1, {P_REG_16(DE)}, inst_DEC, "DEC DE"},
    {0x2B, 2, 1, {P_REG_16(HL)}, inst_DEC, "DEC HL"},
    {0x3B, 2, 1, {P_REG_16(SP)}, inst_DEC, "DEC SP"},

    //ALU : Compare

    {0xBF, 1, 1, {P_REG_8(A), P_REG_8(A)}, inst_CP, "CP A, A"},
    {0xB8, 1, 1, {P_REG_8(A), P_REG_8(B)}, inst_CP, "CP A, B"},
    {0xB9, 1, 1, {P_REG_8(A), P_REG_8(C)}, inst_CP, "CP A, C"},
    {0xBA, 1, 1, {P_REG_8(A), P_REG_8(D)}, inst_CP, "CP A, D"},
    {0xBB, 1, 1, {P_REG_8(A), P_REG_8(E)}, inst_CP, "CP A, E"},
    {0xBC, 1, 1, {P_REG_8(A), P_REG_8(H)}, inst_CP, "CP A, H"},
    {0xBD, 1, 1, {P_REG_8(A), P_REG_8(L)}, inst_CP, "CP A, L"},
    {0xBE, 2, 1, {P_REG_8(A), P_IREG_8(HL)}, inst_CP, "CP A, (HL)"},
    {0xFE, 2, 2, {P_REG_8(A), P_VAL_8}, inst_CP, "CP A, #"},

    // Rotation

    {0x07, 1, 1, {P_REG_8(A)}, inst_RLC, "RLC A"},
    {0x17, 1, 1, {P_REG_8(A)}, inst_RL, "RL A"},
    {0x0F, 1, 1, {P_REG_8(A)}, inst_RRC, "RRC A"},
    {0x1F, 1, 1, {P_REG_8(A)}, inst_RR, "RR A"},

    // Jumps

    {0xC3, 3, 0, {P_VAL_16, P_RAW(CONDITION_NONE)}, inst_JP, "JP nn"},
    {0xC2, 3, 0, {P_VAL_16, P_RAW(CONDITION_NZ)}, inst_JP, "JP NZ, nn"},
    {0xCA, 3, 0, {P_VAL_16, P_RAW(CONDITION_Z)}, inst_JP, "JP Z, nn"},
    {0xD2, 3, 0, {P_VAL_16, P_RAW(CONDITION_NC)}, inst_JP, "JP NC, nn"},
    {0xDA, 3, 0, {P_VAL_16, P_RAW(CONDITION_C)}, inst_JP, "JP C, nn"},
    {0xE9, 1, 0, {P_REG_16(HL), P_RAW(CONDITION_NONE)}, inst_JP, "JP (HL)"},

    {0x18, 2, 2, {P_VAL_8, P_RAW(CONDITION_NONE)}, inst_JR, "JR n"},
    {0x20, 2, 2, {P_VAL_8, P_RAW(CONDITION_NZ)}, inst_JR, "JR NZ, n"},
    {0x28, 2, 2, {P_VAL_8, P_RAW(CONDITION_Z)}, inst_JR, "JR Z, n"},
    {0x30, 2, 2, {P_VAL_8, P_RAW(CONDITION_NC)}, inst_JR, "JR NC, n"},
    {0x38, 2, 2, {P_VAL_8, P_RAW(CONDITION_C)}, inst_JR, "JR C, n"},

    // Calls

    {0xCD, 3, 0, {P_VAL_16, P_RAW(CONDITION_NONE)}, inst_CALL, "CALL nn"},
    {0xC4, 3, 0, {P_VAL_16, P_RAW(CONDITION_NZ)}, inst_CALL, "CALL NZ, nn"},
    {0xCC, 3, 0, {P_VAL_16, P_RAW(CONDITION_Z)}, inst_CALL, "CALL Z, nn"},
    {0xD4, 3, 0, {P_VAL_16, P_RAW(CONDITION_NC)}, inst_CALL, "CALL NC, nn"},
    {0xDC, 3, 0, {P_VAL_16, P_RAW(CONDITION_C)}, inst_CALL, "CALL C, nn"},

    // Restarts

    {0xC7, 8, 0, {P_RAW(0x00), P_RAW(CONDITION_NONE)}, inst_RST, "RST 00H"},
    {0xCF, 8, 0, {P_RAW(0x08), P_RAW(CONDITION_NONE)}, inst_RST, "RST 08H"},
    {0xD7, 8, 0, {P_RAW(0x10), P_RAW(CONDITION_NONE)}, inst_RST, "RST 10H"},
    {0xDF, 8, 0, {P_RAW(0x18), P_RAW(CONDITION_NONE)}, inst_RST, "RST 18H"},
    {0xE7, 8, 0, {P_RAW(0x20), P_RAW(CONDITION_NONE)}, inst_RST, "RST 20H"},
    {0xEF, 8, 0, {P_RAW(0x28), P_RAW(CONDITION_NONE)}, inst_RST, "RST 28H"},
    {0xF7, 8, 0, {P_RAW(0x30), P_RAW(CONDITION_NONE)}, inst_RST, "RST 30H"},
    {0xFF, 8, 0, {P_RAW(0x38), P_RAW(CONDITION_NONE)}, inst_RST, "RST 38H"},

    // Returns

    {0xC9, 2, 0, {P_IREG_16(SP), P_RAW(CONDITION_NONE)}, inst_RET, "RET"},
    {0xC0, 2, 0, {P_IREG_16(SP), P_RAW(CONDITION_NZ)}, inst_RET, "RET NZ"},
    {0xC8, 2, 0, {P_IREG_16(SP), P_RAW(CONDITION_Z)}, inst_RET, "RET Z"},
    {0xD0, 2, 0, {P_IREG_16(SP), P_RAW(CONDITION_NC)}, inst_RET, "RET NC"},
    {0xD8, 2, 0, {P_IREG_16(SP), P_RAW(CONDITION_C)}, inst_RET, "RET C"},

    {0xD9, 2, 0, {P_IREG_16(SP), P_RAW(CONDITION_NONE)}, inst_RETI, "RETI"},

    // Misc

    {0x27, 1, 1, {P_REG_8(A)}, inst_DAA, "DAA"},
    {0x2F, 1, 1, {P_REG_8(A)}, inst_CPL, "CPL"},
    {0x3F, 1, 1, {}, inst_CCF, "CCF"},
    {0x37, 1, 1, {}, inst_SCF, "SCF"},

    {0x00, 1, 1, {}, inst_NOP, "NOP"},
    {0x76, 1, 1, {}, inst_HALT, "HALT"},
    {0x10, 1, 2, {}, inst_NOP, "STOP"},

    {0xF3, 1, 1, {}, inst_DI, "DI"},
    {0xFB, 1, 1, {}, inst_EI, "EI"},

    // CB prefixed instructions

    {0xCB, 0, 2, {P_VAL_8}, inst_CB_prefix, "CB prefixed op"},

    // END

    {0, 0, 0, {}, NULL, NULL}
  };

const t_instruction	**instructions = NULL;

void	init_instructions()
{
  int	i;

  instructions = xalloc(sizeof(t_instruction*) * 0x100);
  i = 0;
  while (inst_tab[i].func)
    {
      if (instructions[inst_tab[i].opcode] != NULL)
	emu_warn("init_instructions", "Opcode collision");
      instructions[inst_tab[i].opcode] = inst_tab + i;
      i++;
    }
}
