/**
 * @file atarist.h
 * @brief Atari ST
 * @copyright Copyright (C) 1999-2005, 2016 Free Software Foundation, Inc.
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

#ifndef _ATARIST_H_
#define _ATARIST_H_

#include "reiconv_defines.h"

static const unsigned short atarist_2uni[128] = {
  /* 0x80 */
  0x00c7, 0x00fc, 0x00e9, 0x00e2, 0x00e4, 0x00e0, 0x00e5, 0x00e7,
  0x00ea, 0x00eb, 0x00e8, 0x00ef, 0x00ee, 0x00ec, 0x00c4, 0x00c5,
  /* 0x90 */
  0x00c9, 0x00e6, 0x00c6, 0x00f4, 0x00f6, 0x00f2, 0x00fb, 0x00f9,
  0x00ff, 0x00d6, 0x00dc, 0x00a2, 0x00a3, 0x00a5, 0x00df, 0x0192,
  /* 0xa0 */
  0x00e1, 0x00ed, 0x00f3, 0x00fa, 0x00f1, 0x00d1, 0x00aa, 0x00ba,
  0x00bf, 0x2310, 0x00ac, 0x00bd, 0x00bc, 0x00a1, 0x00ab, 0x00bb,
  /* 0xb0 */
  0x00e3, 0x00f5, 0x00d8, 0x00f8, 0x0153, 0x0152, 0x00c0, 0x00c3,
  0x00d5, 0x00a8, 0x00b4, 0x2020, 0x00b6, 0x00a9, 0x00ae, 0x2122,
  /* 0xc0 */
  0x0133, 0x0132, 0x05d0, 0x05d1, 0x05d2, 0x05d3, 0x05d4, 0x05d5,
  0x05d6, 0x05d7, 0x05d8, 0x05d9, 0x05db, 0x05dc, 0x05de, 0x05e0,
  /* 0xd0 */
  0x05e1, 0x05e2, 0x05e4, 0x05e6, 0x05e7, 0x05e8, 0x05e9, 0x05ea,
  0x05df, 0x05da, 0x05dd, 0x05e3, 0x05e5, 0x00a7, 0x2227, 0x221e,
  /* 0xe0 */
  0x03b1, 0x03b2, 0x0393, 0x03c0, 0x03a3, 0x03c3, 0x00b5, 0x03c4,
  0x03a6, 0x0398, 0x03a9, 0x03b4, 0x222e, 0x03c6, 0x2208, 0x2229,
  /* 0xf0 */
  0x2261, 0x00b1, 0x2265, 0x2264, 0x2320, 0x2321, 0x00f7, 0x2248,
  0x00b0, 0x2219, 0x00b7, 0x221a, 0x207f, 0x00b2, 0x00b3, 0x00af,
};

static int atarist_mbtowc(conv_t conv, ucs4_t *pwc, const unsigned char *s, size_t n)
{
    unsigned char c = *s;
    if (c < 0x80)
        *pwc = (ucs4_t)c;
    else
        *pwc = (ucs4_t)atarist_2uni[c - 0x80];
    return 1;
}

static const unsigned char atarist_page00[96] = {
  0x00, 0xad, 0x9b, 0x9c, 0x00, 0x9d, 0x00, 0xdd, /* 0xa0-0xa7 */
  0xb9, 0xbd, 0xa6, 0xae, 0xaa, 0x00, 0xbe, 0xff, /* 0xa8-0xaf */
  0xf8, 0xf1, 0xfd, 0xfe, 0xba, 0xe6, 0xbc, 0xfa, /* 0xb0-0xb7 */
  0x00, 0x00, 0xa7, 0xaf, 0xac, 0xab, 0x00, 0xa8, /* 0xb8-0xbf */
  0xb6, 0x00, 0x00, 0xb7, 0x8e, 0x8f, 0x92, 0x80, /* 0xc0-0xc7 */
  0x00, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xc8-0xcf */
  0x00, 0xa5, 0x00, 0x00, 0x00, 0xb8, 0x99, 0x00, /* 0xd0-0xd7 */
  0xb2, 0x00, 0x00, 0x00, 0x9a, 0x00, 0x00, 0x9e, /* 0xd8-0xdf */
  0x85, 0xa0, 0x83, 0xb0, 0x84, 0x86, 0x91, 0x87, /* 0xe0-0xe7 */
  0x8a, 0x82, 0x88, 0x89, 0x8d, 0xa1, 0x8c, 0x8b, /* 0xe8-0xef */
  0x00, 0xa4, 0x95, 0xa2, 0x93, 0xb1, 0x94, 0xf6, /* 0xf0-0xf7 */
  0xb3, 0x97, 0xa3, 0x96, 0x81, 0x00, 0x00, 0x98, /* 0xf8-0xff */
};
static const unsigned char atarist_page01[104] = {
  0x00, 0x00, 0xc1, 0xc0, 0x00, 0x00, 0x00, 0x00, /* 0x30-0x37 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x38-0x3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x40-0x47 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x48-0x4f */
  0x00, 0x00, 0xb5, 0xb4, 0x00, 0x00, 0x00, 0x00, /* 0x50-0x57 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x58-0x5f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x60-0x67 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x68-0x6f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x70-0x77 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x78-0x7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x80-0x87 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x88-0x8f */
  0x00, 0x00, 0x9f, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x90-0x97 */
};
static const unsigned char atarist_page03[56] = {
  0x00, 0x00, 0x00, 0xe2, 0x00, 0x00, 0x00, 0x00, /* 0x90-0x97 */
  0xe9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x98-0x9f */
  0x00, 0x00, 0x00, 0xe4, 0x00, 0x00, 0xe8, 0x00, /* 0xa0-0xa7 */
  0x00, 0xea, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xa8-0xaf */
  0x00, 0xe0, 0xe1, 0x00, 0xeb, 0x00, 0x00, 0x00, /* 0xb0-0xb7 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xb8-0xbf */
  0xe3, 0x00, 0x00, 0xe5, 0xe7, 0x00, 0xed, 0x00, /* 0xc0-0xc7 */
};
static const unsigned char atarist_page05[32] = {
  0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, /* 0xd0-0xd7 */
  0xca, 0xcb, 0xd9, 0xcc, 0xcd, 0xda, 0xce, 0xd8, /* 0xd8-0xdf */
  0xcf, 0xd0, 0xd1, 0xdb, 0xd2, 0xdc, 0xd3, 0xd4, /* 0xe0-0xe7 */
  0xd5, 0xd6, 0xd7, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xe8-0xef */
};
static const unsigned char atarist_page22[96] = {
  0xee, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x08-0x0f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10-0x17 */
  0x00, 0xf9, 0xfb, 0x00, 0x00, 0x00, 0xdf, 0x00, /* 0x18-0x1f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xde, /* 0x20-0x27 */
  0x00, 0xef, 0x00, 0x00, 0x00, 0x00, 0xec, 0x00, /* 0x28-0x2f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x30-0x37 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x38-0x3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x40-0x47 */
  0xf7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x48-0x4f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x50-0x57 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x58-0x5f */
  0x00, 0xf0, 0x00, 0x00, 0xf3, 0xf2, 0x00, 0x00, /* 0x60-0x67 */
};
static const unsigned char atarist_page23[24] = {
  0xa9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10-0x17 */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x18-0x1f */
  0xf4, 0xf5, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x20-0x27 */
};

static int atarist_wctomb(conv_t conv, unsigned char *r, ucs4_t wc, size_t n)
{
    unsigned char c = 0;
    if (wc < 0x0080)
    {
        *r = wc;
        return 1;
    }
    else if (wc >= 0x00a0 && wc < 0x0100)
        c = atarist_page00[wc - 0x00a0];
    else if (wc >= 0x0130 && wc < 0x0198)
        c = atarist_page01[wc - 0x0130];
    else if (wc >= 0x0390 && wc < 0x03c8)
        c = atarist_page03[wc - 0x0390];
    else if (wc >= 0x05d0 && wc < 0x05f0)
        c = atarist_page05[wc - 0x05d0];
    else if (wc == 0x2020)
        c = 0xbb;
    else if (wc == 0x207f)
        c = 0xfc;
    else if (wc == 0x2122)
        c = 0xbf;
    else if (wc >= 0x2208 && wc < 0x2268)
        c = atarist_page22[wc - 0x2208];
    else if (wc >= 0x2310 && wc < 0x2328)
        c = atarist_page23[wc - 0x2310];
    if (c != 0)
    {
        *r = c;
        return 1;
    }
    return RET_ILUNI;
}

#endif /* _ATARIST_H_ */
