/*
 * Copyright (C) 1999-2023 Free Software Foundation, Inc.
 * This file is part of the cppp-reiconv library.
 *
 * The cppp-reiconv library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either version 2
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

/*
 * IBM-1047
 */

static const unsigned short ebcdic1047_2uni[256] = {
  /* 0x00 */
  0x0000, 0x0001, 0x0002, 0x0003, 0x009c, 0x0009, 0x0086, 0x007f,
  0x0097, 0x008d, 0x008e, 0x000b, 0x000c, 0x000d, 0x000e, 0x000f,
  /* 0x10 */
  0x0010, 0x0011, 0x0012, 0x0013, 0x009d, 0x0085, 0x0008, 0x0087,
  0x0018, 0x0019, 0x0092, 0x008f, 0x001c, 0x001d, 0x001e, 0x001f,
  /* 0x20 */
  0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x000a, 0x0017, 0x001b,
  0x0088, 0x0089, 0x008a, 0x008b, 0x008c, 0x0005, 0x0006, 0x0007,
  /* 0x30 */
  0x0090, 0x0091, 0x0016, 0x0093, 0x0094, 0x0095, 0x0096, 0x0004,
  0x0098, 0x0099, 0x009a, 0x009b, 0x0014, 0x0015, 0x009e, 0x001a,
  /* 0x40 */
  0x0020, 0x00a0, 0x00e2, 0x00e4, 0x00e0, 0x00e1, 0x00e3, 0x00e5,
  0x00e7, 0x00f1, 0x00a2, 0x002e, 0x003c, 0x0028, 0x002b, 0x007c,
  /* 0x50 */
  0x0026, 0x00e9, 0x00ea, 0x00eb, 0x00e8, 0x00ed, 0x00ee, 0x00ef,
  0x00ec, 0x00df, 0x0021, 0x0024, 0x002a, 0x0029, 0x003b, 0x005e,
  /* 0x60 */
  0x002d, 0x002f, 0x00c2, 0x00c4, 0x00c0, 0x00c1, 0x00c3, 0x00c5,
  0x00c7, 0x00d1, 0x00a6, 0x002c, 0x0025, 0x005f, 0x003e, 0x003f,
  /* 0x70 */
  0x00f8, 0x00c9, 0x00ca, 0x00cb, 0x00c8, 0x00cd, 0x00ce, 0x00cf,
  0x00cc, 0x0060, 0x003a, 0x0023, 0x0040, 0x0027, 0x003d, 0x0022,
  /* 0x80 */
  0x00d8, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
  0x0068, 0x0069, 0x00ab, 0x00bb, 0x00f0, 0x00fd, 0x00fe, 0x00b1,
  /* 0x90 */
  0x00b0, 0x006a, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f, 0x0070,
  0x0071, 0x0072, 0x00aa, 0x00ba, 0x00e6, 0x00b8, 0x00c6, 0x00a4,
  /* 0xa0 */
  0x00b5, 0x007e, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077, 0x0078,
  0x0079, 0x007a, 0x00a1, 0x00bf, 0x00d0, 0x005b, 0x00de, 0x00ae,
  /* 0xb0 */
  0x00ac, 0x00a3, 0x00a5, 0x00b7, 0x00a9, 0x00a7, 0x00b6, 0x00bc,
  0x00bd, 0x00be, 0x00dd, 0x00a8, 0x00af, 0x005d, 0x00b4, 0x00d7,
  /* 0xc0 */
  0x007b, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
  0x0048, 0x0049, 0x00ad, 0x00f4, 0x00f6, 0x00f2, 0x00f3, 0x00f5,
  /* 0xd0 */
  0x007d, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f, 0x0050,
  0x0051, 0x0052, 0x00b9, 0x00fb, 0x00fc, 0x00f9, 0x00fa, 0x00ff,
  /* 0xe0 */
  0x005c, 0x00f7, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057, 0x0058,
  0x0059, 0x005a, 0x00b2, 0x00d4, 0x00d6, 0x00d2, 0x00d3, 0x00d5,
  /* 0xf0 */
  0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
  0x0038, 0x0039, 0x00b3, 0x00db, 0x00dc, 0x00d9, 0x00da, 0x009f,
};

static int
ebcdic1047_mbtowc (conv_t conv, ucs4_t *pwc, const unsigned char *s, size_t n)
{
  unsigned char c = *s;
  *pwc = (ucs4_t) ebcdic1047_2uni[c];
  return 1;
}

static const unsigned char ebcdic1047_page00[256] = {
  0x00, 0x01, 0x02, 0x03, 0x37, 0x2d, 0x2e, 0x2f, /* 0x00-0x07 */
  0x16, 0x05, 0x25, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, /* 0x08-0x0f */
  0x10, 0x11, 0x12, 0x13, 0x3c, 0x3d, 0x32, 0x26, /* 0x10-0x17 */
  0x18, 0x19, 0x3f, 0x27, 0x1c, 0x1d, 0x1e, 0x1f, /* 0x18-0x1f */
  0x40, 0x5a, 0x7f, 0x7b, 0x5b, 0x6c, 0x50, 0x7d, /* 0x20-0x27 */
  0x4d, 0x5d, 0x5c, 0x4e, 0x6b, 0x60, 0x4b, 0x61, /* 0x28-0x2f */
  0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, /* 0x30-0x37 */
  0xf8, 0xf9, 0x7a, 0x5e, 0x4c, 0x7e, 0x6e, 0x6f, /* 0x38-0x3f */
  0x7c, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, /* 0x40-0x47 */
  0xc8, 0xc9, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, /* 0x48-0x4f */
  0xd7, 0xd8, 0xd9, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, /* 0x50-0x57 */
  0xe7, 0xe8, 0xe9, 0xad, 0xe0, 0xbd, 0x5f, 0x6d, /* 0x58-0x5f */
  0x79, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, /* 0x60-0x67 */
  0x88, 0x89, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, /* 0x68-0x6f */
  0x97, 0x98, 0x99, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, /* 0x70-0x77 */
  0xa7, 0xa8, 0xa9, 0xc0, 0x4f, 0xd0, 0xa1, 0x07, /* 0x78-0x7f */
  0x20, 0x21, 0x22, 0x23, 0x24, 0x15, 0x06, 0x17, /* 0x80-0x87 */
  0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x09, 0x0a, 0x1b, /* 0x88-0x8f */
  0x30, 0x31, 0x1a, 0x33, 0x34, 0x35, 0x36, 0x08, /* 0x90-0x97 */
  0x38, 0x39, 0x3a, 0x3b, 0x04, 0x14, 0x3e, 0xff, /* 0x98-0x9f */
  0x41, 0xaa, 0x4a, 0xb1, 0x9f, 0xb2, 0x6a, 0xb5, /* 0xa0-0xa7 */
  0xbb, 0xb4, 0x9a, 0x8a, 0xb0, 0xca, 0xaf, 0xbc, /* 0xa8-0xaf */
  0x90, 0x8f, 0xea, 0xfa, 0xbe, 0xa0, 0xb6, 0xb3, /* 0xb0-0xb7 */
  0x9d, 0xda, 0x9b, 0x8b, 0xb7, 0xb8, 0xb9, 0xab, /* 0xb8-0xbf */
  0x64, 0x65, 0x62, 0x66, 0x63, 0x67, 0x9e, 0x68, /* 0xc0-0xc7 */
  0x74, 0x71, 0x72, 0x73, 0x78, 0x75, 0x76, 0x77, /* 0xc8-0xcf */
  0xac, 0x69, 0xed, 0xee, 0xeb, 0xef, 0xec, 0xbf, /* 0xd0-0xd7 */
  0x80, 0xfd, 0xfe, 0xfb, 0xfc, 0xba, 0xae, 0x59, /* 0xd8-0xdf */
  0x44, 0x45, 0x42, 0x46, 0x43, 0x47, 0x9c, 0x48, /* 0xe0-0xe7 */
  0x54, 0x51, 0x52, 0x53, 0x58, 0x55, 0x56, 0x57, /* 0xe8-0xef */
  0x8c, 0x49, 0xcd, 0xce, 0xcb, 0xcf, 0xcc, 0xe1, /* 0xf0-0xf7 */
  0x70, 0xdd, 0xde, 0xdb, 0xdc, 0x8d, 0x8e, 0xdf, /* 0xf8-0xff */
};

static int
ebcdic1047_wctomb (conv_t conv, unsigned char *r, ucs4_t wc, size_t n)
{
  unsigned char c = 0;
  if (wc < 0x0100)
    c = ebcdic1047_page00[wc];
  if (c != 0 || wc == 0) {
    *r = c;
    return 1;
  }
  return RET_ILUNI;
}
