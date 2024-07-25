/*
 * Copyright (C) 2001, 2004, 2011 Free Software Foundation, Inc.
 * This file is part of the cppp-reiconv library.
 *
 * The cppp-reiconv library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * The cppp-reiconv library is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with the cppp-reiconv library; see the file LICENSE.
 * If not, see <https://www.gnu.org/licenses/>.
 */

/* Combining characters used in Vietnamese encodings CP1258, TCVN. */

#ifndef _VIETCOMB_H
#define _VIETCOMB_H

/* Relevant combining characters:
   0x0300, 0x0301, 0x0303, 0x0309, 0x0323. */

/* Composition tables for each of the relevant combining characters. */
static const struct { unsigned short base; unsigned short composed; } viet_comp_table_data[] = {
#define viet_comp_table0300_idx 0
#define viet_comp_table0300_len 31
  { 0x0041, 0x00C0 },
  { 0x0045, 0x00C8 },
  { 0x0049, 0x00CC },
  { 0x004E, 0x01F8 },
  { 0x004F, 0x00D2 },
  { 0x0055, 0x00D9 },
  { 0x0057, 0x1E80 },
  { 0x0059, 0x1EF2 },
  { 0x0061, 0x00E0 },
  { 0x0065, 0x00E8 },
  { 0x0069, 0x00EC },
  { 0x006E, 0x01F9 },
  { 0x006F, 0x00F2 },
  { 0x0075, 0x00F9 },
  { 0x0077, 0x1E81 },
  { 0x0079, 0x1EF3 },
  { 0x00A8, 0x1FED },
  { 0x00C2, 0x1EA6 },
  { 0x00CA, 0x1EC0 },
  { 0x00D4, 0x1ED2 },
  { 0x00DC, 0x01DB },
  { 0x00E2, 0x1EA7 },
  { 0x00EA, 0x1EC1 },
  { 0x00F4, 0x1ED3 },
  { 0x00FC, 0x01DC },
  { 0x0102, 0x1EB0 },
  { 0x0103, 0x1EB1 },
/*{ 0x0112, 0x1E14 },*/
/*{ 0x0113, 0x1E15 },*/
/*{ 0x014C, 0x1E50 },*/
/*{ 0x014D, 0x1E51 },*/
  { 0x01A0, 0x1EDC },
  { 0x01A1, 0x1EDD },
  { 0x01AF, 0x1EEA },
  { 0x01B0, 0x1EEB },
#define viet_comp_table0301_idx (viet_comp_table0300_idx+viet_comp_table0300_len)
#define viet_comp_table0301_len 63
  { 0x0041, 0x00C1 },
  { 0x0043, 0x0106 },
  { 0x0045, 0x00C9 },
  { 0x0047, 0x01F4 },
  { 0x0049, 0x00CD },
  { 0x004B, 0x1E30 },
  { 0x004C, 0x0139 },
  { 0x004D, 0x1E3E },
  { 0x004E, 0x0143 },
  { 0x004F, 0x00D3 },
  { 0x0050, 0x1E54 },
  { 0x0052, 0x0154 },
  { 0x0053, 0x015A },
  { 0x0055, 0x00DA },
  { 0x0057, 0x1E82 },
  { 0x0059, 0x00DD },
  { 0x005A, 0x0179 },
  { 0x0061, 0x00E1 },
  { 0x0063, 0x0107 },
  { 0x0065, 0x00E9 },
  { 0x0067, 0x01F5 },
  { 0x0069, 0x00ED },
  { 0x006B, 0x1E31 },
  { 0x006C, 0x013A },
  { 0x006D, 0x1E3F },
  { 0x006E, 0x0144 },
  { 0x006F, 0x00F3 },
  { 0x0070, 0x1E55 },
  { 0x0072, 0x0155 },
  { 0x0073, 0x015B },
  { 0x0075, 0x00FA },
  { 0x0077, 0x1E83 },
  { 0x0079, 0x00FD },
  { 0x007A, 0x017A },
  { 0x00A8, 0x0385 }, /* prefer U+0385 over U+1FEE */
  { 0x00C2, 0x1EA4 },
  { 0x00C5, 0x01FA },
  { 0x00C6, 0x01FC },
  { 0x00C7, 0x1E08 },
  { 0x00CA, 0x1EBE },
  { 0x00CF, 0x1E2E },
  { 0x00D4, 0x1ED0 },
  { 0x00D5, 0x1E4C },
  { 0x00D8, 0x01FE },
  { 0x00DC, 0x01D7 },
  { 0x00E2, 0x1EA5 },
  { 0x00E5, 0x01FB },
  { 0x00E6, 0x01FD },
  { 0x00E7, 0x1E09 },
  { 0x00EA, 0x1EBF },
  { 0x00EF, 0x1E2F },
  { 0x00F4, 0x1ED1 },
  { 0x00F5, 0x1E4D },
  { 0x00F8, 0x01FF },
  { 0x00FC, 0x01D8 },
  { 0x0102, 0x1EAE },
  { 0x0103, 0x1EAF },
/*{ 0x0112, 0x1E16 },*/
/*{ 0x0113, 0x1E17 },*/
/*{ 0x014C, 0x1E52 },*/
/*{ 0x014D, 0x1E53 },*/
  { 0x0168, 0x1E78 },
  { 0x0169, 0x1E79 },
  { 0x01A0, 0x1EDA },
  { 0x01A1, 0x1EDB },
  { 0x01AF, 0x1EE8 },
  { 0x01B0, 0x1EE9 },
#define viet_comp_table0303_idx (viet_comp_table0301_idx+viet_comp_table0301_len)
#define viet_comp_table0303_len 34
  { 0x0041, 0x00C3 },
  { 0x0045, 0x1EBC },
  { 0x0049, 0x0128 },
  { 0x004E, 0x00D1 },
  { 0x004F, 0x00D5 },
  { 0x0055, 0x0168 },
  { 0x0056, 0x1E7C },
  { 0x0059, 0x1EF8 },
  { 0x0061, 0x00E3 },
  { 0x0065, 0x1EBD },
  { 0x0069, 0x0129 },
  { 0x006E, 0x00F1 },
  { 0x006F, 0x00F5 },
  { 0x0075, 0x0169 },
  { 0x0076, 0x1E7D },
  { 0x0079, 0x1EF9 },
  { 0x00C2, 0x1EAA },
  { 0x00CA, 0x1EC4 },
  { 0x00D3, 0x1E4C },
  { 0x00D4, 0x1ED6 },
  { 0x00D6, 0x1E4E },
  { 0x00DA, 0x1E78 },
  { 0x00E2, 0x1EAB },
  { 0x00EA, 0x1EC5 },
  { 0x00F3, 0x1E4D },
  { 0x00F4, 0x1ED7 },
  { 0x00F6, 0x1E4F },
  { 0x00FA, 0x1E79 },
  { 0x0102, 0x1EB4 },
  { 0x0103, 0x1EB5 },
  { 0x01A0, 0x1EE0 },
  { 0x01A1, 0x1EE1 },
  { 0x01AF, 0x1EEE },
  { 0x01B0, 0x1EEF },
#define viet_comp_table0309_idx (viet_comp_table0303_idx+viet_comp_table0303_len)
#define viet_comp_table0309_len 24
  { 0x0041, 0x1EA2 },
  { 0x0045, 0x1EBA },
  { 0x0049, 0x1EC8 },
  { 0x004F, 0x1ECE },
  { 0x0055, 0x1EE6 },
  { 0x0059, 0x1EF6 },
  { 0x0061, 0x1EA3 },
  { 0x0065, 0x1EBB },
  { 0x0069, 0x1EC9 },
  { 0x006F, 0x1ECF },
  { 0x0075, 0x1EE7 },
  { 0x0079, 0x1EF7 },
  { 0x00C2, 0x1EA8 },
  { 0x00CA, 0x1EC2 },
  { 0x00D4, 0x1ED4 },
  { 0x00E2, 0x1EA9 },
  { 0x00EA, 0x1EC3 },
  { 0x00F4, 0x1ED5 },
  { 0x0102, 0x1EB2 },
  { 0x0103, 0x1EB3 },
  { 0x01A0, 0x1EDE },
  { 0x01A1, 0x1EDF },
  { 0x01AF, 0x1EEC },
  { 0x01B0, 0x1EED },
#define viet_comp_table0323_idx (viet_comp_table0309_idx+viet_comp_table0309_len)
#define viet_comp_table0323_len 50
  { 0x0041, 0x1EA0 },
  { 0x0042, 0x1E04 },
  { 0x0044, 0x1E0C },
  { 0x0045, 0x1EB8 },
  { 0x0048, 0x1E24 },
  { 0x0049, 0x1ECA },
  { 0x004B, 0x1E32 },
  { 0x004C, 0x1E36 },
  { 0x004D, 0x1E42 },
  { 0x004E, 0x1E46 },
  { 0x004F, 0x1ECC },
  { 0x0052, 0x1E5A },
  { 0x0053, 0x1E62 },
  { 0x0054, 0x1E6C },
  { 0x0055, 0x1EE4 },
  { 0x0056, 0x1E7E },
  { 0x0057, 0x1E88 },
  { 0x0059, 0x1EF4 },
  { 0x005A, 0x1E92 },
  { 0x0061, 0x1EA1 },
  { 0x0062, 0x1E05 },
  { 0x0064, 0x1E0D },
  { 0x0065, 0x1EB9 },
  { 0x0068, 0x1E25 },
  { 0x0069, 0x1ECB },
  { 0x006B, 0x1E33 },
  { 0x006C, 0x1E37 },
  { 0x006D, 0x1E43 },
  { 0x006E, 0x1E47 },
  { 0x006F, 0x1ECD },
  { 0x0072, 0x1E5B },
  { 0x0073, 0x1E63 },
  { 0x0074, 0x1E6D },
  { 0x0075, 0x1EE5 },
  { 0x0076, 0x1E7F },
  { 0x0077, 0x1E89 },
  { 0x0079, 0x1EF5 },
  { 0x007A, 0x1E93 },
  { 0x00C2, 0x1EAC },
  { 0x00CA, 0x1EC6 },
  { 0x00D4, 0x1ED8 },
  { 0x00E2, 0x1EAD },
  { 0x00EA, 0x1EC7 },
  { 0x00F4, 0x1ED9 },
  { 0x0102, 0x1EB6 },
  { 0x0103, 0x1EB7 },
  { 0x01A0, 0x1EE2 },
  { 0x01A1, 0x1EE3 },
  { 0x01AF, 0x1EF0 },
  { 0x01B0, 0x1EF1 },
};
static const struct { unsigned int len; unsigned int idx; } viet_comp_table[] = {
  { viet_comp_table0300_len, viet_comp_table0300_idx },
  { viet_comp_table0301_len, viet_comp_table0301_idx },
  { viet_comp_table0303_len, viet_comp_table0303_idx },
  { viet_comp_table0309_len, viet_comp_table0309_idx },
  { viet_comp_table0323_len, viet_comp_table0323_idx },
};

/* Decomposition table for the relevant Unicode characters. */
struct viet_decomp { unsigned short composed; unsigned int base : 12; int comb1 : 4; };
static const struct viet_decomp viet_decomp_table[] = {
  { 0x00B4, 0x0020, 1 }, /* compatibility decomposition - for TCVN only */
  { 0x00C0, 0x0041, 0 },
  { 0x00C1, 0x0041, 1 },
  { 0x00C3, 0x0041, 2 },
  { 0x00C8, 0x0045, 0 },
  { 0x00C9, 0x0045, 1 },
  { 0x00CC, 0x0049, 0 },
  { 0x00CD, 0x0049, 1 },
  { 0x00D1, 0x004E, 2 },
  { 0x00D2, 0x004F, 0 },
  { 0x00D3, 0x004F, 1 },
  { 0x00D5, 0x004F, 2 },
  { 0x00D9, 0x0055, 0 },
  { 0x00DA, 0x0055, 1 },
  { 0x00DD, 0x0059, 1 },
  { 0x00E0, 0x0061, 0 },
  { 0x00E1, 0x0061, 1 },
  { 0x00E3, 0x0061, 2 },
  { 0x00E8, 0x0065, 0 },
  { 0x00E9, 0x0065, 1 },
  { 0x00EC, 0x0069, 0 },
  { 0x00ED, 0x0069, 1 },
  { 0x00F1, 0x006E, 2 },
  { 0x00F2, 0x006F, 0 },
  { 0x00F3, 0x006F, 1 },
  { 0x00F5, 0x006F, 2 },
  { 0x00F9, 0x0075, 0 },
  { 0x00FA, 0x0075, 1 },
  { 0x00FD, 0x0079, 1 },
  { 0x0106, 0x0043, 1 },
  { 0x0107, 0x0063, 1 },
  { 0x0128, 0x0049, 2 },
  { 0x0129, 0x0069, 2 },
  { 0x0139, 0x004C, 1 },
  { 0x013A, 0x006C, 1 },
  { 0x0143, 0x004E, 1 },
  { 0x0144, 0x006E, 1 },
  { 0x0154, 0x0052, 1 },
  { 0x0155, 0x0072, 1 },
  { 0x015A, 0x0053, 1 },
  { 0x015B, 0x0073, 1 },
  { 0x0168, 0x0055, 2 },
  { 0x0169, 0x0075, 2 },
  { 0x0179, 0x005A, 1 },
  { 0x017A, 0x007A, 1 },
  { 0x01D7, 0x00DC, 1 },
  { 0x01D8, 0x00FC, 1 },
  { 0x01DB, 0x00DC, 0 },
  { 0x01DC, 0x00FC, 0 },
  { 0x01F4, 0x0047, 1 },
  { 0x01F5, 0x0067, 1 },
  { 0x01F8, 0x004E, 0 },
  { 0x01F9, 0x006E, 0 },
  { 0x01FA, 0x00C5, 1 },
  { 0x01FB, 0x00E5, 1 },
  { 0x01FC, 0x00C6, 1 },
  { 0x01FD, 0x00E6, 1 },
  { 0x01FE, 0x00D8, 1 },
  { 0x01FF, 0x00F8, 1 },
  { 0x02DC, 0x0020, 2 }, /* compatibility decomposition - for TCVN only */
  { 0x0385, 0x00A8, 1 },
  { 0x1E04, 0x0042, 4 },
  { 0x1E05, 0x0062, 4 },
  { 0x1E08, 0x00C7, 1 },
  { 0x1E09, 0x00E7, 1 },
  { 0x1E0C, 0x0044, 4 },
  { 0x1E0D, 0x0064, 4 },
  { 0x1E24, 0x0048, 4 },
  { 0x1E25, 0x0068, 4 },
  { 0x1E2E, 0x00CF, 1 },
  { 0x1E2F, 0x00EF, 1 },
  { 0x1E30, 0x004B, 1 },
  { 0x1E31, 0x006B, 1 },
  { 0x1E32, 0x004B, 4 },
  { 0x1E33, 0x006B, 4 },
  { 0x1E36, 0x004C, 4 },
  { 0x1E37, 0x006C, 4 },
  { 0x1E3E, 0x004D, 1 },
  { 0x1E3F, 0x006D, 1 },
  { 0x1E42, 0x004D, 4 },
  { 0x1E43, 0x006D, 4 },
  { 0x1E46, 0x004E, 4 },
  { 0x1E47, 0x006E, 4 },
  { 0x1E4C, 0x00D3, 2 }, /*{ 0x1E4C, 0x00D5, 1 },*/ /*{ 0x1E4C, 0x004F, 1, 2 },*/
  { 0x1E4D, 0x00F3, 2 }, /*{ 0x1E4D, 0x00F5, 1 },*/ /*{ 0x1E4D, 0x006F, 1, 2 },*/
  { 0x1E4E, 0x00D6, 2 },
  { 0x1E4F, 0x00F6, 2 },
  { 0x1E54, 0x0050, 1 },
  { 0x1E55, 0x0070, 1 },
  { 0x1E5A, 0x0052, 4 },
  { 0x1E5B, 0x0072, 4 },
  { 0x1E62, 0x0053, 4 },
  { 0x1E63, 0x0073, 4 },
  { 0x1E6C, 0x0054, 4 },
  { 0x1E6D, 0x0074, 4 },
  { 0x1E78, 0x00DA, 2 }, /*{ 0x1E78, 0x0168, 1 },*/ /*{ 0x1E78, 0x0055, 1, 2 },*/
  { 0x1E79, 0x00FA, 2 }, /*{ 0x1E79, 0x0169, 1 },*/ /*{ 0x1E79, 0x0075, 1, 2 },*/
  { 0x1E7C, 0x0056, 2 },
  { 0x1E7D, 0x0076, 2 },
  { 0x1E7E, 0x0056, 4 },
  { 0x1E7F, 0x0076, 4 },
  { 0x1E80, 0x0057, 0 },
  { 0x1E81, 0x0077, 0 },
  { 0x1E82, 0x0057, 1 },
  { 0x1E83, 0x0077, 1 },
  { 0x1E88, 0x0057, 4 },
  { 0x1E89, 0x0077, 4 },
  { 0x1E92, 0x005A, 4 },
  { 0x1E93, 0x007A, 4 },
  { 0x1EA0, 0x0041, 4 },
  { 0x1EA1, 0x0061, 4 },
  { 0x1EA2, 0x0041, 3 },
  { 0x1EA3, 0x0061, 3 },
  { 0x1EA4, 0x00C2, 1 },
  { 0x1EA5, 0x00E2, 1 },
  { 0x1EA6, 0x00C2, 0 },
  { 0x1EA7, 0x00E2, 0 },
  { 0x1EA8, 0x00C2, 3 },
  { 0x1EA9, 0x00E2, 3 },
  { 0x1EAA, 0x00C2, 2 },
  { 0x1EAB, 0x00E2, 2 },
  { 0x1EAC, 0x00C2, 4 },
  { 0x1EAD, 0x00E2, 4 },
  { 0x1EAE, 0x0102, 1 },
  { 0x1EAF, 0x0103, 1 },
  { 0x1EB0, 0x0102, 0 },
  { 0x1EB1, 0x0103, 0 },
  { 0x1EB2, 0x0102, 3 },
  { 0x1EB3, 0x0103, 3 },
  { 0x1EB4, 0x0102, 2 },
  { 0x1EB5, 0x0103, 2 },
  { 0x1EB6, 0x0102, 4 },
  { 0x1EB7, 0x0103, 4 },
  { 0x1EB8, 0x0045, 4 },
  { 0x1EB9, 0x0065, 4 },
  { 0x1EBA, 0x0045, 3 },
  { 0x1EBB, 0x0065, 3 },
  { 0x1EBC, 0x0045, 2 },
  { 0x1EBD, 0x0065, 2 },
  { 0x1EBE, 0x00CA, 1 },
  { 0x1EBF, 0x00EA, 1 },
  { 0x1EC0, 0x00CA, 0 },
  { 0x1EC1, 0x00EA, 0 },
  { 0x1EC2, 0x00CA, 3 },
  { 0x1EC3, 0x00EA, 3 },
  { 0x1EC4, 0x00CA, 2 },
  { 0x1EC5, 0x00EA, 2 },
  { 0x1EC6, 0x00CA, 4 },
  { 0x1EC7, 0x00EA, 4 },
  { 0x1EC8, 0x0049, 3 },
  { 0x1EC9, 0x0069, 3 },
  { 0x1ECA, 0x0049, 4 },
  { 0x1ECB, 0x0069, 4 },
  { 0x1ECC, 0x004F, 4 },
  { 0x1ECD, 0x006F, 4 },
  { 0x1ECE, 0x004F, 3 },
  { 0x1ECF, 0x006F, 3 },
  { 0x1ED0, 0x00D4, 1 },
  { 0x1ED1, 0x00F4, 1 },
  { 0x1ED2, 0x00D4, 0 },
  { 0x1ED3, 0x00F4, 0 },
  { 0x1ED4, 0x00D4, 3 },
  { 0x1ED5, 0x00F4, 3 },
  { 0x1ED6, 0x00D4, 2 },
  { 0x1ED7, 0x00F4, 2 },
  { 0x1ED8, 0x00D4, 4 },
  { 0x1ED9, 0x00F4, 4 },
  { 0x1EDA, 0x01A0, 1 },
  { 0x1EDB, 0x01A1, 1 },
  { 0x1EDC, 0x01A0, 0 },
  { 0x1EDD, 0x01A1, 0 },
  { 0x1EDE, 0x01A0, 3 },
  { 0x1EDF, 0x01A1, 3 },
  { 0x1EE0, 0x01A0, 2 },
  { 0x1EE1, 0x01A1, 2 },
  { 0x1EE2, 0x01A0, 4 },
  { 0x1EE3, 0x01A1, 4 },
  { 0x1EE4, 0x0055, 4 },
  { 0x1EE5, 0x0075, 4 },
  { 0x1EE6, 0x0055, 3 },
  { 0x1EE7, 0x0075, 3 },
  { 0x1EE8, 0x01AF, 1 },
  { 0x1EE9, 0x01B0, 1 },
  { 0x1EEA, 0x01AF, 0 },
  { 0x1EEB, 0x01B0, 0 },
  { 0x1EEC, 0x01AF, 3 },
  { 0x1EED, 0x01B0, 3 },
  { 0x1EEE, 0x01AF, 2 },
  { 0x1EEF, 0x01B0, 2 },
  { 0x1EF0, 0x01AF, 4 },
  { 0x1EF1, 0x01B0, 4 },
  { 0x1EF2, 0x0059, 0 },
  { 0x1EF3, 0x0079, 0 },
  { 0x1EF4, 0x0059, 4 },
  { 0x1EF5, 0x0079, 4 },
  { 0x1EF6, 0x0059, 3 },
  { 0x1EF7, 0x0079, 3 },
  { 0x1EF8, 0x0059, 2 },
  { 0x1EF9, 0x0079, 2 },
  { 0x1FED, 0x00A8, 0 },
  { 0x1FEE, 0x00A8, 1 }, /* U+1FEE => U+0385 => U+00A8 U+0301 */
};

#endif /* _VIETCOMB_H */
