/**
 * @file tds565.h
 * @brief TDS565
 * @copyright Copyright (C) 1999-2002, 2016 Free Software Foundation, Inc.
 * @copyright Copyright (C) 2024 The C++ Plus Project.
 */
/*
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

#ifndef _TDS565_H_
#define _TDS565_H_

#include "reiconv_defines.h"

static const unsigned short tds565_2uni[64] = {
  /* 0x40 */
  0x0040, 0x0041, 0x0042, 0x00c7, 0x0044, 0x0045, 0x00c4, 0x0046,
  0x0047, 0x0048, 0x0049, 0x004a, 0x017d, 0x004b, 0x004c, 0x004d,
  /* 0x50 */
  0x004e, 0x0147, 0x004f, 0x00d6, 0x0050, 0x0052, 0x0053, 0x015e,
  0x0054, 0x0055, 0x00dc, 0x0057, 0x0059, 0x00dd, 0x005a, 0x005f,
  /* 0x60 */
  0x2116, 0x0061, 0x0062, 0x00e7, 0x0064, 0x0065, 0x00e4, 0x0066,
  0x0067, 0x0068, 0x0069, 0x006a, 0x017e, 0x006b, 0x006c, 0x006d,
  /* 0x70 */
  0x006e, 0x0148, 0x006f, 0x00f6, 0x0070, 0x0072, 0x0073, 0x015f,
  0x0074, 0x0075, 0x00fc, 0x0077, 0x0079, 0x00fd, 0x007a, 0x007f,
};

static int
tds565_mbtowc (conv_t conv, ucs4_t *pwc, const unsigned char *s, size_t n)
{
  unsigned char c = *s;
  if (c < 0x40) {
    *pwc = (ucs4_t) c;
    return 1;
  }
  else if (c < 0x80) {
    *pwc = (ucs4_t) tds565_2uni[c-0x40];
    return 1;
  }
  return RET_ILSEQ;
}

static const unsigned char tds565_page00[64] = {
  0x40, 0x41, 0x42, 0x00, 0x44, 0x45, 0x47, 0x48, /* 0x40-0x47 */
  0x49, 0x4a, 0x4b, 0x4d, 0x4e, 0x4f, 0x50, 0x52, /* 0x48-0x4f */
  0x54, 0x00, 0x55, 0x56, 0x58, 0x59, 0x00, 0x5b, /* 0x50-0x57 */
  0x00, 0x5c, 0x5e, 0x00, 0x00, 0x00, 0x00, 0x5f, /* 0x58-0x5f */
  0x00, 0x61, 0x62, 0x00, 0x64, 0x65, 0x67, 0x68, /* 0x60-0x67 */
  0x69, 0x6a, 0x6b, 0x6d, 0x6e, 0x6f, 0x70, 0x72, /* 0x68-0x6f */
  0x74, 0x00, 0x75, 0x76, 0x78, 0x79, 0x00, 0x7b, /* 0x70-0x77 */
  0x00, 0x7c, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x7f, /* 0x78-0x7f */
};
static const unsigned char tds565_page00_1[64] = {
  0x00, 0x00, 0x00, 0x00, 0x46, 0x00, 0x00, 0x43, /* 0xc0-0xc7 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xc8-0xcf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x53, 0x00, /* 0xd0-0xd7 */
  0x00, 0x00, 0x00, 0x00, 0x5a, 0x5d, 0x00, 0x00, /* 0xd8-0xdf */
  0x00, 0x00, 0x00, 0x00, 0x66, 0x00, 0x00, 0x63, /* 0xe0-0xe7 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xe8-0xef */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x00, /* 0xf0-0xf7 */
  0x00, 0x00, 0x00, 0x00, 0x7a, 0x7d, 0x00, 0x00, /* 0xf8-0xff */
};
static const unsigned char tds565_page01[64] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x51, /* 0x40-0x47 */
  0x71, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x48-0x4f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x50-0x57 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x77, /* 0x58-0x5f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x60-0x67 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x68-0x6f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x70-0x77 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0x6c, 0x00, /* 0x78-0x7f */
};

static int
tds565_wctomb (conv_t conv, unsigned char *r, ucs4_t wc, size_t n)
{
  unsigned char c = 0;
  if (wc < 0x0040) {
    *r = wc;
    return 1;
  }
  else if (wc >= 0x0040 && wc < 0x0080)
    c = tds565_page00[wc-0x0040];
  else if (wc >= 0x00c0 && wc < 0x0100)
    c = tds565_page00_1[wc-0x00c0];
  else if (wc >= 0x0140 && wc < 0x0180)
    c = tds565_page01[wc-0x0140];
  else if (wc == 0x2116)
    c = 0x60;
  if (c != 0) {
    *r = c;
    return 1;
  }
  return RET_ILUNI;
}

#endif /* _TDS565_H_ */
