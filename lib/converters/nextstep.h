/**
 * @file nextstep.h
 * @brief NEXTSTEP
 * @copyright Copyright (C) 1999-2001, 2016 Free Software Foundation, Inc.
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

#ifndef _NEXTSTEP_H_
#define _NEXTSTEP_H_

#include "reiconv_defines.h"

static const unsigned short nextstep_2uni[128] = {
  /* 0x80 */
  0x00a0, 0x00c0, 0x00c1, 0x00c2, 0x00c3, 0x00c4, 0x00c5, 0x00c7,
  0x00c8, 0x00c9, 0x00ca, 0x00cb, 0x00cc, 0x00cd, 0x00ce, 0x00cf,
  /* 0x90 */
  0x00d0, 0x00d1, 0x00d2, 0x00d3, 0x00d4, 0x00d5, 0x00d6, 0x00d9,
  0x00da, 0x00db, 0x00dc, 0x00dd, 0x00de, 0x00b5, 0x00d7, 0x00f7,
  /* 0xa0 */
  0x00a9, 0x00a1, 0x00a2, 0x00a3, 0x2044, 0x00a5, 0x0192, 0x00a7,
  0x00a4, 0x2019, 0x201c, 0x00ab, 0x2039, 0x203a, 0xfb01, 0xfb02,
  /* 0xb0 */
  0x00ae, 0x2013, 0x2020, 0x2021, 0x00b7, 0x00a6, 0x00b6, 0x2022,
  0x201a, 0x201e, 0x201d, 0x00bb, 0x2026, 0x2030, 0x00ac, 0x00bf,
  /* 0xc0 */
  0x00b9, 0x02cb, 0x00b4, 0x02c6, 0x02dc, 0x00af, 0x02d8, 0x02d9,
  0x00a8, 0x00b2, 0x02da, 0x00b8, 0x00b3, 0x02dd, 0x02db, 0x02c7,
  /* 0xd0 */
  0x2014, 0x00b1, 0x00bc, 0x00bd, 0x00be, 0x00e0, 0x00e1, 0x00e2,
  0x00e3, 0x00e4, 0x00e5, 0x00e7, 0x00e8, 0x00e9, 0x00ea, 0x00eb,
  /* 0xe0 */
  0x00ec, 0x00c6, 0x00ed, 0x00aa, 0x00ee, 0x00ef, 0x00f0, 0x00f1,
  0x0141, 0x00d8, 0x0152, 0x00ba, 0x00f2, 0x00f3, 0x00f4, 0x00f5,
  /* 0xf0 */
  0x00f6, 0x00e6, 0x00f9, 0x00fa, 0x00fb, 0x0131, 0x00fc, 0x00fd,
  0x0142, 0x00f8, 0x0153, 0x00df, 0x00fe, 0x00ff, 0xfffd, 0xfffd,
};

static int nextstep_mbtowc(conv_t conv, ucs4_t *pwc, const unsigned char *s, size_t n)
{
    unsigned char c = *s;
    if (c < 0x80)
    {
        *pwc = (ucs4_t)c;
        return 1;
    }
    else
    {
        unsigned short wc = nextstep_2uni[c - 0x80];
        if (wc != 0xfffd)
        {
            *pwc = (ucs4_t)wc;
            return 1;
        }
    }
    return RET_ILSEQ;
}

static const unsigned char nextstep_page00[96] = {
  0x80, 0xa1, 0xa2, 0xa3, 0xa8, 0xa5, 0xb5, 0xa7, /* 0xa0-0xa7 */
  0xc8, 0xa0, 0xe3, 0xab, 0xbe, 0x00, 0xb0, 0xc5, /* 0xa8-0xaf */
  0x00, 0xd1, 0xc9, 0xcc, 0xc2, 0x9d, 0xb6, 0xb4, /* 0xb0-0xb7 */
  0xcb, 0xc0, 0xeb, 0xbb, 0xd2, 0xd3, 0xd4, 0xbf, /* 0xb8-0xbf */
  0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0xe1, 0x87, /* 0xc0-0xc7 */
  0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, /* 0xc8-0xcf */
  0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x9e, /* 0xd0-0xd7 */
  0xe9, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c, 0xfb, /* 0xd8-0xdf */
  0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xf1, 0xdb, /* 0xe0-0xe7 */
  0xdc, 0xdd, 0xde, 0xdf, 0xe0, 0xe2, 0xe4, 0xe5, /* 0xe8-0xef */
  0xe6, 0xe7, 0xec, 0xed, 0xee, 0xef, 0xf0, 0x9f, /* 0xf0-0xf7 */
  0xf9, 0xf2, 0xf3, 0xf4, 0xf6, 0xf7, 0xfc, 0xfd, /* 0xf8-0xff */
};
static const unsigned char nextstep_page01[104] = {
  0x00, 0xf5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x30-0x37 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x38-0x3f */
  0x00, 0xe8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x40-0x47 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x48-0x4f */
  0x00, 0x00, 0xea, 0xfa, 0x00, 0x00, 0x00, 0x00, /* 0x50-0x57 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x58-0x5f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x60-0x67 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x68-0x6f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x70-0x77 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x78-0x7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x80-0x87 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x88-0x8f */
  0x00, 0x00, 0xa6, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x90-0x97 */
};
static const unsigned char nextstep_page02[32] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc3, 0xcf, /* 0xc0-0xc7 */
  0x00, 0x00, 0x00, 0xc1, 0x00, 0x00, 0x00, 0x00, /* 0xc8-0xcf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xd0-0xd7 */
  0xc6, 0xc7, 0xca, 0xce, 0xc4, 0xcd, 0x00, 0x00, /* 0xd8-0xdf */
};
static const unsigned char nextstep_page20[56] = {
  0x00, 0x00, 0x00, 0xb1, 0xd0, 0x00, 0x00, 0x00, /* 0x10-0x17 */
  0x00, 0xa9, 0xb8, 0x00, 0xaa, 0xba, 0xb9, 0x00, /* 0x18-0x1f */
  0xb2, 0xb3, 0xb7, 0x00, 0x00, 0x00, 0xbc, 0x00, /* 0x20-0x27 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x28-0x2f */
  0xbd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x30-0x37 */
  0x00, 0xac, 0xad, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x38-0x3f */
  0x00, 0x00, 0x00, 0x00, 0xa4, 0x00, 0x00, 0x00, /* 0x40-0x47 */
};
static const unsigned char nextstep_pagefb[8] = {
  0x00, 0xae, 0xaf, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x00-0x07 */
};

static int nextstep_wctomb(conv_t conv, unsigned char *r, ucs4_t wc, size_t n)
{
    unsigned char c = 0;
    if (wc < 0x0080)
    {
        *r = wc;
        return 1;
    }
    else if (wc >= 0x00a0 && wc < 0x0100)
        c = nextstep_page00[wc - 0x00a0];
    else if (wc >= 0x0130 && wc < 0x0198)
        c = nextstep_page01[wc - 0x0130];
    else if (wc >= 0x02c0 && wc < 0x02e0)
        c = nextstep_page02[wc - 0x02c0];
    else if (wc >= 0x2010 && wc < 0x2048)
        c = nextstep_page20[wc - 0x2010];
    else if (wc >= 0xfb00 && wc < 0xfb08)
        c = nextstep_pagefb[wc - 0xfb00];
    if (c != 0)
    {
        *r = c;
        return 1;
    }
    return RET_ILUNI;
}

#endif /* _NEXTSTEP_H_ */
