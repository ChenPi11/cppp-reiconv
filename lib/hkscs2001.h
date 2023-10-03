/*
 * Copyright (C) 1999-2006, 2012, 2016 Free Software Foundation, Inc.
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
 * License along with the cppp-reiconv library; see the file COPYING.
 * If not, see <https://www.gnu.org/licenses/>.
 */

/*
 * HKSCS:2001
 */

static const unsigned short hkscs2001_2uni_page8c[123] = {
  /* 0x8c */
  0x0a3b, 0x1cfe, 0x5273, 0x37a6, 0x02c9, 0x2d8f, 0x414e, 0x1d77,
  0x12f5, 0x0620, 0x45cd, 0x0059, 0x4830, 0x1622, 0x4f32, 0x30a7,
  0x31f6, 0x1e91, 0x1819, 0x20ba, 0x3e81, 0x5307, 0x018b, 0x3a80,
  0x0610, 0x24e4, 0x2102, 0x0bae, 0x4d0f, 0x0409, 0x1a63, 0x54ba,
  0x0523, 0x2c0f, 0x38fd, 0x252a, 0x5147, 0x4fea, 0x3455, 0x1d4d,
  0x0c24, 0x3c7e, 0x33f4, 0x22d9, 0x4ee3, 0x37a7, 0x23dd, 0x08a3,
  0x09f0, 0x0abc, 0x082f, 0x0917, 0x37a8, 0x0d34, 0x288b, 0x0f92,
  0x0fd0, 0x3bb6, 0x1492, 0x1499, 0x15c2, 0x3d12, 0x178b, 0x3ff9,
  0x1919, 0x1a43, 0x4063, 0x1bff, 0x38fd, 0x1f00, 0x4205, 0x208c,
  0x03db, 0x4413, 0x1115, 0x21b9, 0x2e83, 0x47a4, 0x4695, 0x2593,
  0x26ec, 0x27c3, 0x296c, 0x2af8, 0x2b97, 0x37a9, 0x2d90, 0x37aa,
  0x2fb9, 0x37ab, 0x30cf, 0x2b5f, 0x36e0, 0x3221, 0x37ac, 0x50b9,
  0x393f, 0x0471, 0x05a2, 0x101a, 0x38fd, 0x38fd, 0x38fd, 0x3568,
  0x186b, 0x0576, 0x0e3d, 0x38fd, 0x2bd6, 0x437b, 0x2abf, 0x4c0d,
  0x0781, 0x4a74, 0x137b, 0x4915, 0x4bbe, 0x37ad, 0x37ae, 0x1196,
  0x37af, 0x38fd, 0x295b,
};

static const ucs4_t hkscs2001_2uni_upages[85] = {
  0x03500, 0x03c00, 0x03d00, 0x03e00, 0x04000, 0x04200, 0x04b00, 0x04c00,
  0x04e00, 0x04f00, 0x05000, 0x05100, 0x05300, 0x05400, 0x05700, 0x05800,
  0x05a00, 0x05b00, 0x05c00, 0x05d00, 0x05e00, 0x05f00, 0x06100, 0x06500,
  0x06700, 0x06900, 0x06a00, 0x06c00, 0x06d00, 0x07000, 0x07100, 0x07200,
  0x07300, 0x07400, 0x07600, 0x07700, 0x07800, 0x07a00, 0x07b00, 0x07c00,
  0x07d00, 0x07e00, 0x08200, 0x08500, 0x08600, 0x08800, 0x08b00, 0x08e00,
  0x08f00, 0x09100, 0x09200, 0x09300, 0x09700, 0x09800, 0x09900, 0x09f00,
  0x0ff00, 0x21400, 0x21900, 0x21d00, 0x22000, 0x22700, 0x23200, 0x23300,
  0x23c00, 0x24100, 0x24500, 0x24900, 0x24a00, 0x25100, 0x25600, 0x25c00,
  0x25d00, 0x26b00, 0x26d00, 0x26f00, 0x27100, 0x28700, 0x28900, 0x28a00,
  0x28d00, 0x29900, 0x29c00, 0x2a100, 0x2a200,
};

static int
hkscs2001_mbtowc (conv_t conv, ucs4_t *pwc, const unsigned char *s, size_t n)
{
  unsigned char c1 = s[0];
  if (c1 == (unsigned char)0x8c) {
    if (n >= 2) {
      unsigned char c2 = s[1];
      if ((c2 >= 0x40 && c2 < 0x7f) || (c2 >= 0xa1 && c2 < 0xff)) {
        unsigned int i = 157 * (c1 - 0x80) + (c2 - (c2 >= 0xa1 ? 0x62 : 0x40));
        ucs4_t wc = 0xfffd;
        unsigned short swc;
        {
          if (i < 2007)
            swc = hkscs2001_2uni_page8c[i-1884],
            wc = hkscs2001_2uni_upages[swc>>8] | (swc & 0xff);
        }
        if (wc != 0xfffd) {
          *pwc = wc;
          return 2;
        }
      }
      return RET_ILSEQ;
    }
    return RET_TOOFEW(0);
  }
  return RET_ILSEQ;
}

static const unsigned short hkscs2001_2charset[116] = {
  0x8c4b, 0x8c56, 0x8c44, 0x8caa, 0x8c5d, 0x8cc3, 0x8c60, 0x8ccb,
  0x8cc4, 0x8c58, 0x8c49, 0x8cd2, 0x8c72, 0x8c6f, 0x8c73, 0x8c70,
  0x8c40, 0x8c71, 0x8c5b, 0x8c68, 0x8c75, 0x8ccc, 0x8c77, 0x8c78,
  0x8cc5, 0x8cac, 0x8cd9, 0x8c48, 0x8cd4, 0x8c7a, 0x8c7b, 0x8c7c,
  0x8c4d, 0x8c7e, 0x8c52, 0x8cca, 0x8ca2, 0x8ca3, 0x8c5e, 0x8ca5,
  0x8c41, 0x8c67, 0x8c47, 0x8c51, 0x8ca7, 0x8ca9, 0x8c53, 0x8c5a,
  0x8cad, 0x8c6b, 0x8c6e, 0x8c59, 0x8c63, 0x8cb1, 0x8cb2, 0x8cb3,
  0x8c76, 0x8cdc, 0x8cb4, 0x8cd0, 0x8cb5, 0x8cbd, 0x8cb6, 0x8cce,
  0x8c61, 0x8c45, 0x8cb8, 0x8cae, 0x8cba, 0x8c4f, 0x8cbc, 0x8c50,
  0x8cbf, 0x8c6a, 0x8c66, 0x8cc9, 0x8cbe, 0x8c43, 0x8c6d, 0x8c74,
  0x8cb7, 0x8cb9, 0x8cbb, 0x8cc0, 0x8cd7, 0x8cd8, 0x8cda, 0x8cc2,
  0x8c57, 0x8c79, 0x8c69, 0x8c7d, 0x8c54, 0x8ca1, 0x8ca4, 0x8c46,
  0x8ca8, 0x8ccf, 0x8cab, 0x8c4a, 0x8cb0, 0x8caf, 0x8c4c, 0x8cd5,
  0x8cd3, 0x8cd6, 0x8cd1, 0x8c5c, 0x8c6c, 0x8c4e, 0x8c65, 0x8cc1,
  0x8c64, 0x8c42, 0x8c55, 0x8c5f,
};

static const Summary16 hkscs2001_uni2indx_page35[6] = {
  /* 0x3500 */
  {    0, 0x0000 }, {    0, 0x0000 }, {    0, 0x0000 }, {    0, 0x0000 },
  {    0, 0x0000 }, {    0, 0x0200 },
};
static const Summary16 hkscs2001_uni2indx_page3c[46] = {
  /* 0x3c00 */
  {    1, 0x0000 }, {    1, 0x0000 }, {    1, 0x0000 }, {    1, 0x0000 },
  {    1, 0x0000 }, {    1, 0x0000 }, {    1, 0x0000 }, {    1, 0x0000 },
  {    1, 0x0800 }, {    2, 0x0000 }, {    2, 0x0000 }, {    2, 0x0000 },
  {    2, 0x0000 }, {    2, 0x0000 }, {    2, 0x0000 }, {    2, 0x0000 },
  /* 0x3d00 */
  {    2, 0x0000 }, {    2, 0x0000 }, {    2, 0x0000 }, {    2, 0x0000 },
  {    2, 0x0000 }, {    2, 0x0000 }, {    2, 0x0000 }, {    2, 0x0000 },
  {    2, 0x0000 }, {    2, 0x0000 }, {    2, 0x0000 }, {    2, 0x0000 },
  {    2, 0x0200 }, {    3, 0x0000 }, {    3, 0x0000 }, {    3, 0x0000 },
  /* 0x3e00 */
  {    3, 0x0000 }, {    3, 0x0000 }, {    3, 0x0000 }, {    3, 0x0000 },
  {    3, 0x0000 }, {    3, 0x0000 }, {    3, 0x0000 }, {    3, 0x0000 },
  {    3, 0x0000 }, {    3, 0x0000 }, {    3, 0x0000 }, {    3, 0x0000 },
  {    3, 0x0000 }, {    3, 0x0800 },
};
static const Summary16 hkscs2001_uni2indx_page40[8] = {
  /* 0x4000 */
  {    4, 0x0200 }, {    5, 0x0000 }, {    5, 0x0000 }, {    5, 0x0000 },
  {    5, 0x0000 }, {    5, 0x0000 }, {    5, 0x0000 }, {    5, 0x0002 },
};
static const Summary16 hkscs2001_uni2indx_page42[11] = {
  /* 0x4200 */
  {    6, 0x0000 }, {    6, 0x0000 }, {    6, 0x0008 }, {    7, 0x0000 },
  {    7, 0x0000 }, {    7, 0x0000 }, {    7, 0x0000 }, {    7, 0x0040 },
  {    8, 0x0000 }, {    8, 0x0000 }, {    8, 0x0004 },
};
static const Summary16 hkscs2001_uni2indx_page4b[25] = {
  /* 0x4b00 */
  {    9, 0x0000 }, {    9, 0x0001 }, {   10, 0x0001 }, {   11, 0x0000 },
  {   11, 0x0000 }, {   11, 0x0000 }, {   11, 0x0000 }, {   11, 0x0000 },
  {   11, 0x0000 }, {   11, 0x0000 }, {   11, 0x0000 }, {   11, 0x0000 },
  {   11, 0x0000 }, {   11, 0x0000 }, {   11, 0x0000 }, {   11, 0x0000 },
  /* 0x4c00 */
  {   11, 0x0000 }, {   11, 0x0000 }, {   11, 0x0000 }, {   11, 0x0000 },
  {   11, 0x0000 }, {   11, 0x0000 }, {   11, 0x0000 }, {   11, 0x0000 },
  {   11, 0x0002 },
};
static const Summary16 hkscs2001_uni2indx_page4e[59] = {
  /* 0x4e00 */
  {   12, 0x0000 }, {   12, 0x0000 }, {   12, 0x8000 }, {   13, 0x0000 },
  {   13, 0x0000 }, {   13, 0x0000 }, {   13, 0x0000 }, {   13, 0x0000 },
  {   13, 0x0000 }, {   13, 0x0000 }, {   13, 0x0008 }, {   14, 0x0000 },
  {   14, 0x0000 }, {   14, 0x0000 }, {   14, 0x0000 }, {   14, 0x0000 },
  /* 0x4f00 */
  {   14, 0x0000 }, {   14, 0x0080 }, {   15, 0x0000 }, {   15, 0x0000 },
  {   15, 0x0000 }, {   15, 0x0000 }, {   15, 0x0000 }, {   15, 0x0000 },
  {   15, 0x0000 }, {   15, 0x0000 }, {   15, 0x0000 }, {   15, 0x0000 },
  {   15, 0x0000 }, {   15, 0x0000 }, {   15, 0x0000 }, {   15, 0x0001 },
  /* 0x5000 */
  {   16, 0x0000 }, {   16, 0x0000 }, {   16, 0x0000 }, {   16, 0x0800 },
  {   17, 0x0000 }, {   17, 0x0000 }, {   17, 0x0000 }, {   17, 0x0000 },
  {   17, 0x0000 }, {   17, 0x0000 }, {   17, 0x0000 }, {   17, 0x1000 },
  {   18, 0x0000 }, {   18, 0x0000 }, {   18, 0x0000 }, {   18, 0x0000 },
  /* 0x5100 */
  {   18, 0x0000 }, {   18, 0x0000 }, {   18, 0x0000 }, {   18, 0x0000 },
  {   18, 0x0000 }, {   18, 0x0000 }, {   18, 0x0000 }, {   18, 0x0000 },
  {   18, 0x0000 }, {   18, 0x0000 }, {   18, 0x4000 },
};
static const Summary16 hkscs2001_uni2indx_page53[20] = {
  /* 0x5300 */
  {   19, 0x0000 }, {   19, 0x0000 }, {   19, 0x0010 }, {   20, 0x0000 },
  {   20, 0x0000 }, {   20, 0x0000 }, {   20, 0x0000 }, {   20, 0x0000 },
  {   20, 0x0000 }, {   20, 0x0000 }, {   20, 0x0000 }, {   20, 0x0000 },
  {   20, 0x0000 }, {   20, 0x0000 }, {   20, 0x0000 }, {   20, 0x0000 },
  /* 0x5400 */
  {   20, 0x0000 }, {   20, 0x0000 }, {   20, 0x0000 }, {   20, 0x0010 },
};
static const Summary16 hkscs2001_uni2indx_page57[30] = {
  /* 0x5700 */
  {   21, 0x0000 }, {   21, 0x0000 }, {   21, 0x0000 }, {   21, 0x2000 },
  {   22, 0x0000 }, {   22, 0x0000 }, {   22, 0x0000 }, {   22, 0x0000 },
  {   22, 0x0000 }, {   22, 0x0000 }, {   22, 0x0000 }, {   22, 0x0000 },
  {   22, 0x0000 }, {   22, 0x0000 }, {   22, 0x0000 }, {   22, 0x0000 },
  /* 0x5800 */
  {   22, 0x0000 }, {   22, 0x0000 }, {   22, 0x0000 }, {   22, 0x0000 },
  {   22, 0x0000 }, {   22, 0x0000 }, {   22, 0x0000 }, {   22, 0x0000 },
  {   22, 0x0000 }, {   22, 0x0004 }, {   23, 0x0000 }, {   23, 0x0000 },
  {   23, 0x0000 }, {   23, 0x0001 },
};
static const Summary16 hkscs2001_uni2indx_page5a[93] = {
  /* 0x5a00 */
  {   24, 0x0000 }, {   24, 0x0400 }, {   25, 0x0000 }, {   25, 0x0000 },
  {   25, 0x0000 }, {   25, 0x0000 }, {   25, 0x0000 }, {   25, 0x0000 },
  {   25, 0x0000 }, {   25, 0x0000 }, {   25, 0x0000 }, {   25, 0x0000 },
  {   25, 0x0000 }, {   25, 0x0000 }, {   25, 0x0000 }, {   25, 0x0000 },
  /* 0x5b00 */
  {   25, 0x0000 }, {   25, 0x0020 }, {   26, 0x0000 }, {   26, 0x0000 },
  {   26, 0x0000 }, {   26, 0x0000 }, {   26, 0x0000 }, {   26, 0x0000 },
  {   26, 0x0000 }, {   26, 0x0040 }, {   27, 0x0000 }, {   27, 0x0000 },
  {   27, 0x0000 }, {   27, 0x0000 }, {   27, 0x0000 }, {   27, 0x0000 },
  /* 0x5c00 */
  {   27, 0x0000 }, {   27, 0x0000 }, {   27, 0x0000 }, {   27, 0x0000 },
  {   27, 0x0000 }, {   27, 0x0000 }, {   27, 0x0000 }, {   27, 0x0000 },
  {   27, 0x0000 }, {   27, 0x0000 }, {   27, 0x0000 }, {   27, 0x0000 },
  {   27, 0x0000 }, {   27, 0x0000 }, {   27, 0x0000 }, {   27, 0x0020 },
  /* 0x5d00 */
  {   28, 0x0000 }, {   28, 0x0000 }, {   28, 0x0000 }, {   28, 0x0000 },
  {   28, 0x0000 }, {   28, 0x0000 }, {   28, 0x0000 }, {   28, 0x0800 },
  {   29, 0x0000 }, {   29, 0x0000 }, {   29, 0x0000 }, {   29, 0x0000 },
  {   29, 0x0000 }, {   29, 0x0000 }, {   29, 0x0000 }, {   29, 0x0000 },
  /* 0x5e00 */
  {   29, 0x0000 }, {   29, 0x0000 }, {   29, 0x0000 }, {   29, 0x0000 },
  {   29, 0x0000 }, {   29, 0x0000 }, {   29, 0x0000 }, {   29, 0x0000 },
  {   29, 0x0000 }, {   29, 0x0204 }, {   31, 0x0000 }, {   31, 0x0000 },
  {   31, 0x0000 }, {   31, 0x0000 }, {   31, 0x0000 }, {   31, 0x0000 },
  /* 0x5f00 */
  {   31, 0x0000 }, {   31, 0x0000 }, {   31, 0x0000 }, {   31, 0x0000 },
  {   31, 0x0000 }, {   31, 0x0000 }, {   31, 0x0000 }, {   31, 0x0000 },
  {   31, 0x0000 }, {   31, 0x0000 }, {   31, 0x0000 }, {   31, 0x0000 },
  {   31, 0x0004 },
};
static const Summary16 hkscs2001_uni2indx_page61[3] = {
  /* 0x6100 */
  {   32, 0x0000 }, {   32, 0x0000 }, {   32, 0x0004 },
};
static const Summary16 hkscs2001_uni2indx_page65[9] = {
  /* 0x6500 */
  {   33, 0x0000 }, {   33, 0x0000 }, {   33, 0x0000 }, {   33, 0x0000 },
  {   33, 0x0000 }, {   33, 0x0000 }, {   33, 0x0000 }, {   33, 0x0000 },
  {   33, 0x0800 },
};
static const Summary16 hkscs2001_uni2indx_page67[7] = {
  /* 0x6700 */
  {   34, 0x0000 }, {   34, 0x0200 }, {   35, 0x0000 }, {   35, 0x0000 },
  {   35, 0x0000 }, {   35, 0x0000 }, {   35, 0x0800 },
};
static const Summary16 hkscs2001_uni2indx_page69[23] = {
  /* 0x6900 */
  {   36, 0x0000 }, {   36, 0x0200 }, {   37, 0x0000 }, {   37, 0x0000 },
  {   37, 0x0000 }, {   37, 0x0000 }, {   37, 0x0000 }, {   37, 0x0000 },
  {   37, 0x0000 }, {   37, 0x0000 }, {   37, 0x0000 }, {   37, 0x0000 },
  {   37, 0x0000 }, {   37, 0x0000 }, {   37, 0x0000 }, {   37, 0x0000 },
  /* 0x6a00 */
  {   37, 0x0000 }, {   37, 0x0000 }, {   37, 0x0000 }, {   37, 0x0000 },
  {   37, 0x0008 }, {   38, 0x0000 }, {   38, 0x0008 },
};
static const Summary16 hkscs2001_uni2indx_page6c[32] = {
  /* 0x6c00 */
  {   39, 0x0000 }, {   39, 0x0000 }, {   39, 0x0000 }, {   39, 0x0000 },
  {   39, 0x0000 }, {   39, 0x0000 }, {   39, 0x0000 }, {   39, 0x0000 },
  {   39, 0x0000 }, {   39, 0x0000 }, {   39, 0x0000 }, {   39, 0x0000 },
  {   39, 0x0000 }, {   39, 0x0000 }, {   39, 0x0000 }, {   39, 0x8000 },
  /* 0x6d00 */
  {   40, 0x0000 }, {   40, 0x0000 }, {   40, 0x0000 }, {   40, 0x0000 },
  {   40, 0x0000 }, {   40, 0x0000 }, {   40, 0x0000 }, {   40, 0x0000 },
  {   40, 0x0000 }, {   40, 0x0000 }, {   40, 0x0000 }, {   40, 0x0000 },
  {   40, 0x0000 }, {   40, 0x0000 }, {   40, 0x0000 }, {   40, 0x4000 },
};
static const Summary16 hkscs2001_uni2indx_page70[76] = {
  /* 0x7000 */
  {   41, 0x0000 }, {   41, 0x0000 }, {   41, 0x0000 }, {   41, 0x0000 },
  {   41, 0x2000 }, {   42, 0x0000 }, {   42, 0x0000 }, {   42, 0x0080 },
  {   43, 0x0000 }, {   43, 0x0000 }, {   43, 0x0000 }, {   43, 0x0000 },
  {   43, 0x0000 }, {   43, 0x0000 }, {   43, 0x0000 }, {   43, 0x0000 },
  /* 0x7100 */
  {   43, 0x0000 }, {   43, 0x0000 }, {   43, 0x0000 }, {   43, 0x0000 },
  {   43, 0x0000 }, {   43, 0x0000 }, {   43, 0x0000 }, {   43, 0x0000 },
  {   43, 0x0000 }, {   43, 0x0002 }, {   44, 0x0000 }, {   44, 0x0000 },
  {   44, 0x0000 }, {   44, 0x0000 }, {   44, 0x0000 }, {   44, 0x0000 },
  /* 0x7200 */
  {   44, 0x0001 }, {   45, 0x0000 }, {   45, 0x0000 }, {   45, 0x0000 },
  {   45, 0x0000 }, {   45, 0x0000 }, {   45, 0x0000 }, {   45, 0x0000 },
  {   45, 0x0000 }, {   45, 0x0000 }, {   45, 0x0000 }, {   45, 0x0000 },
  {   45, 0x0000 }, {   45, 0x0000 }, {   45, 0x0000 }, {   45, 0x0000 },
  /* 0x7300 */
  {   45, 0x0000 }, {   45, 0x0000 }, {   45, 0x0000 }, {   45, 0x0000 },
  {   45, 0x0000 }, {   45, 0x0000 }, {   45, 0x0000 }, {   45, 0x0000 },
  {   45, 0x1000 }, {   46, 0x0000 }, {   46, 0x0000 }, {   46, 0x0400 },
  {   47, 0x0000 }, {   47, 0x0000 }, {   47, 0x0000 }, {   47, 0x0000 },
  /* 0x7400 */
  {   47, 0x0004 }, {   48, 0x0000 }, {   48, 0x0000 }, {   48, 0x0000 },
  {   48, 0x0000 }, {   48, 0x0000 }, {   48, 0x0000 }, {   48, 0x0000 },
  {   48, 0x0000 }, {   48, 0x0000 }, {   48, 0x0000 }, {   48, 0x0200 },
};
static const Summary16 hkscs2001_uni2indx_page76[47] = {
  /* 0x7600 */
  {   49, 0x0000 }, {   49, 0x0000 }, {   49, 0x0000 }, {   49, 0x0000 },
  {   49, 0x0000 }, {   49, 0x0000 }, {   49, 0x0000 }, {   49, 0x0000 },
  {   49, 0x0000 }, {   49, 0x0000 }, {   49, 0x0000 }, {   49, 0x0000 },
  {   49, 0x0000 }, {   49, 0x0200 }, {   50, 0x0000 }, {   50, 0x0000 },
  /* 0x7700 */
  {   50, 0x0000 }, {   50, 0x0000 }, {   50, 0x0000 }, {   50, 0x0000 },
  {   50, 0x0000 }, {   50, 0x0000 }, {   50, 0x0000 }, {   50, 0x0000 },
  {   50, 0x0000 }, {   50, 0x0000 }, {   50, 0x0000 }, {   50, 0x0000 },
  {   50, 0x0000 }, {   50, 0x2000 }, {   51, 0x0000 }, {   51, 0x0000 },
  /* 0x7800 */
  {   51, 0x0000 }, {   51, 0x0000 }, {   51, 0x0000 }, {   51, 0x0000 },
  {   51, 0x0000 }, {   51, 0x0000 }, {   51, 0x0000 }, {   51, 0x0000 },
  {   51, 0x0000 }, {   51, 0x0000 }, {   51, 0x0000 }, {   51, 0x0000 },
  {   51, 0x0000 }, {   51, 0x0000 }, {   51, 0x0010 },
};
static const Summary16 hkscs2001_uni2indx_page7a[71] = {
  /* 0x7a00 */
  {   52, 0x0000 }, {   52, 0x0000 }, {   52, 0x0400 }, {   53, 0x0000 },
  {   53, 0x0000 }, {   53, 0x0000 }, {   53, 0x0000 }, {   53, 0x0000 },
  {   53, 0x0000 }, {   53, 0x0008 }, {   54, 0x0000 }, {   54, 0x0000 },
  {   54, 0x0000 }, {   54, 0x0000 }, {   54, 0x0000 }, {   54, 0x0000 },
  /* 0x7b00 */
  {   54, 0x0000 }, {   54, 0x0000 }, {   54, 0x0000 }, {   54, 0x0000 },
  {   54, 0x0000 }, {   54, 0x0000 }, {   54, 0x0000 }, {   54, 0x0000 },
  {   54, 0x0000 }, {   54, 0x0000 }, {   54, 0x0000 }, {   54, 0x0000 },
  {   54, 0x0000 }, {   54, 0x0000 }, {   54, 0x1000 }, {   55, 0x0000 },
  /* 0x7c00 */
  {   55, 0x0000 }, {   55, 0x0000 }, {   55, 0x0000 }, {   55, 0x0000 },
  {   55, 0x0000 }, {   55, 0x0000 }, {   55, 0x0000 }, {   55, 0x0000 },
  {   55, 0x0000 }, {   55, 0x0000 }, {   55, 0x0000 }, {   55, 0x0000 },
  {   55, 0x0008 }, {   56, 0x0000 }, {   56, 0x0000 }, {   56, 0x0000 },
  /* 0x7d00 */
  {   56, 0x0000 }, {   56, 0x0000 }, {   56, 0x0000 }, {   56, 0x0000 },
  {   56, 0x0000 }, {   56, 0x0000 }, {   56, 0x0000 }, {   56, 0x0000 },
  {   56, 0x0800 }, {   57, 0x0000 }, {   57, 0x0000 }, {   57, 0x0000 },
  {   57, 0x0000 }, {   57, 0x0000 }, {   57, 0x0000 }, {   57, 0x0000 },
  /* 0x7e00 */
  {   57, 0x0000 }, {   57, 0x0000 }, {   57, 0x0000 }, {   57, 0x0000 },
  {   57, 0x0000 }, {   57, 0x0800 }, {   58, 0x1000 },
};
static const Summary16 hkscs2001_uni2indx_page82[16] = {
  /* 0x8200 */
  {   59, 0x0000 }, {   59, 0x0000 }, {   59, 0x0000 }, {   59, 0x0000 },
  {   59, 0x0000 }, {   59, 0x0000 }, {   59, 0x0000 }, {   59, 0x0000 },
  {   59, 0x0000 }, {   59, 0x0000 }, {   59, 0x0000 }, {   59, 0x8000 },
  {   60, 0x0000 }, {   60, 0x0000 }, {   60, 0x0000 }, {   60, 0x0100 },
};
static const Summary16 hkscs2001_uni2indx_page85[17] = {
  /* 0x8500 */
  {   61, 0x0000 }, {   61, 0x0000 }, {   61, 0x0000 }, {   61, 0x0000 },
  {   61, 0x0000 }, {   61, 0x8000 }, {   62, 0x0000 }, {   62, 0x0000 },
  {   62, 0x0000 }, {   62, 0x0080 }, {   63, 0x0000 }, {   63, 0x0000 },
  {   63, 0x0000 }, {   63, 0x0040 }, {   64, 0x0000 }, {   64, 0x0000 },
  /* 0x8600 */
  {   64, 0x8000 },
};
static const Summary16 hkscs2001_uni2indx_page88[10] = {
  /* 0x8800 */
  {   65, 0x0000 }, {   65, 0x0000 }, {   65, 0x0000 }, {   65, 0x0000 },
  {   65, 0x0000 }, {   65, 0x0000 }, {   65, 0x0000 }, {   65, 0x0000 },
  {   65, 0x8000 }, {   66, 0x0001 },
};
static const Summary16 hkscs2001_uni2indx_page8b[9] = {
  /* 0x8b00 */
  {   67, 0x0000 }, {   67, 0x0000 }, {   67, 0x0000 }, {   67, 0x0000 },
  {   67, 0x0000 }, {   67, 0x0000 }, {   67, 0x0000 }, {   67, 0x0000 },
  {   67, 0x0008 },
};
static const Summary16 hkscs2001_uni2indx_page8e[29] = {
  /* 0x8e00 */
  {   68, 0x0000 }, {   68, 0x0000 }, {   68, 0x0000 }, {   68, 0x0000 },
  {   68, 0x0000 }, {   68, 0x0000 }, {   68, 0x0000 }, {   68, 0x0000 },
  {   68, 0x0000 }, {   68, 0x0000 }, {   68, 0x0000 }, {   68, 0x0200 },
  {   69, 0x0000 }, {   69, 0x0000 }, {   69, 0x0000 }, {   69, 0x0000 },
  /* 0x8f00 */
  {   69, 0x0000 }, {   69, 0x0000 }, {   69, 0x0000 }, {   69, 0x0000 },
  {   69, 0x0000 }, {   69, 0x0000 }, {   69, 0x0000 }, {   69, 0x0000 },
  {   69, 0x0000 }, {   69, 0x0000 }, {   69, 0x0080 }, {   70, 0x0000 },
  {   70, 0x8000 },
};
static const Summary16 hkscs2001_uni2indx_page91[48] = {
  /* 0x9100 */
  {   71, 0x0000 }, {   71, 0x0000 }, {   71, 0x0000 }, {   71, 0x0000 },
  {   71, 0x0000 }, {   71, 0x0000 }, {   71, 0x0000 }, {   71, 0x0000 },
  {   71, 0x0000 }, {   71, 0x0000 }, {   71, 0x0000 }, {   71, 0x0000 },
  {   71, 0x0000 }, {   71, 0x0000 }, {   71, 0x0000 }, {   71, 0x0040 },
  /* 0x9200 */
  {   72, 0x0000 }, {   72, 0x0000 }, {   72, 0x0002 }, {   73, 0x0000 },
  {   73, 0x0000 }, {   73, 0x0000 }, {   73, 0x0000 }, {   73, 0x0000 },
  {   73, 0x0000 }, {   73, 0x0000 }, {   73, 0x0000 }, {   73, 0x0000 },
  {   73, 0x0000 }, {   73, 0x0000 }, {   73, 0x0000 }, {   73, 0x0000 },
  /* 0x9300 */
  {   73, 0x0000 }, {   73, 0x0000 }, {   73, 0x0000 }, {   73, 0x0000 },
  {   73, 0x0000 }, {   73, 0x0000 }, {   73, 0x0000 }, {   73, 0x0000 },
  {   73, 0x0000 }, {   73, 0x0000 }, {   73, 0x0000 }, {   73, 0x0000 },
  {   73, 0x0000 }, {   73, 0x0000 }, {   73, 0x0000 }, {   73, 0x0010 },
};
static const Summary16 hkscs2001_uni2indx_page97[47] = {
  /* 0x9700 */
  {   74, 0x0000 }, {   74, 0x0000 }, {   74, 0x0000 }, {   74, 0x0000 },
  {   74, 0x0000 }, {   74, 0x0020 }, {   75, 0x0000 }, {   75, 0x0000 },
  {   75, 0x0000 }, {   75, 0x0000 }, {   75, 0x0000 }, {   75, 0x0000 },
  {   75, 0x0000 }, {   75, 0x0000 }, {   75, 0x0000 }, {   75, 0x0000 },
  /* 0x9800 */
  {   75, 0x0000 }, {   75, 0x0000 }, {   75, 0x0000 }, {   75, 0x0000 },
  {   75, 0x0000 }, {   75, 0x0000 }, {   75, 0x0100 }, {   76, 0x0000 },
  {   76, 0x0000 }, {   76, 0x0000 }, {   76, 0x0000 }, {   76, 0x0000 },
  {   76, 0x0000 }, {   76, 0x0000 }, {   76, 0x0000 }, {   76, 0x0000 },
  /* 0x9900 */
  {   76, 0x0000 }, {   76, 0x0000 }, {   76, 0x0000 }, {   76, 0x0000 },
  {   76, 0x0000 }, {   76, 0x0000 }, {   76, 0x0000 }, {   76, 0x0000 },
  {   76, 0x0000 }, {   76, 0x0000 }, {   76, 0x0000 }, {   76, 0x0000 },
  {   76, 0x0000 }, {   76, 0x0000 }, {   76, 0x0001 },
};
static const Summary16 hkscs2001_uni2indx_page9f[11] = {
  /* 0x9f00 */
  {   77, 0x0000 }, {   77, 0x0000 }, {   77, 0x0000 }, {   77, 0x0000 },
  {   77, 0x0000 }, {   77, 0x0000 }, {   77, 0x0000 }, {   77, 0x0000 },
  {   77, 0x0000 }, {   77, 0x0000 }, {   77, 0xffc0 },
};
static const Summary16 hkscs2001_uni2indx_page214[4] = {
  /* 0x21400 */
  {   87, 0x0000 }, {   87, 0x0000 }, {   87, 0x0000 }, {   87, 0x8000 },
};
static const Summary16 hkscs2001_uni2indx_page219[9] = {
  /* 0x21900 */
  {   88, 0x0000 }, {   88, 0x0000 }, {   88, 0x0000 }, {   88, 0x0000 },
  {   88, 0x0000 }, {   88, 0x0000 }, {   88, 0x0000 }, {   88, 0x0000 },
  {   88, 0x0001 },
};
static const Summary16 hkscs2001_uni2indx_page21d[12] = {
  /* 0x21d00 */
  {   89, 0x0000 }, {   89, 0x0000 }, {   89, 0x0000 }, {   89, 0x0000 },
  {   89, 0x0000 }, {   89, 0x0000 }, {   89, 0x0000 }, {   89, 0x0000 },
  {   89, 0x0000 }, {   89, 0x0000 }, {   89, 0x0000 }, {   89, 0x0040 },
};
static const Summary16 hkscs2001_uni2indx_page220[8] = {
  /* 0x22000 */
  {   90, 0x0000 }, {   90, 0x0000 }, {   90, 0x0000 }, {   90, 0x0000 },
  {   90, 0x0000 }, {   90, 0x0000 }, {   90, 0x0000 }, {   90, 0x4000 },
};
static const Summary16 hkscs2001_uni2indx_page227[2] = {
  /* 0x22700 */
  {   91, 0x0000 }, {   91, 0x0004 },
};
static const Summary16 hkscs2001_uni2indx_page232[32] = {
  /* 0x23200 */
  {   92, 0x0000 }, {   92, 0x0000 }, {   92, 0x0000 }, {   92, 0x0000 },
  {   92, 0x0000 }, {   92, 0x0000 }, {   92, 0x0000 }, {   92, 0x0000 },
  {   92, 0x0002 }, {   93, 0x0000 }, {   93, 0x0000 }, {   93, 0x0000 },
  {   93, 0x0000 }, {   93, 0x0000 }, {   93, 0x0000 }, {   93, 0x0000 },
  /* 0x23300 */
  {   93, 0x0000 }, {   93, 0x0000 }, {   93, 0x0000 }, {   93, 0x0000 },
  {   93, 0x0000 }, {   93, 0x0000 }, {   93, 0x0000 }, {   93, 0x0000 },
  {   93, 0x0000 }, {   93, 0x0000 }, {   93, 0x0000 }, {   93, 0x0000 },
  {   93, 0x0000 }, {   93, 0x0000 }, {   93, 0x0000 }, {   93, 0x0200 },
};
static const Summary16 hkscs2001_uni2indx_page23c[7] = {
  /* 0x23c00 */
  {   94, 0x0000 }, {   94, 0x0000 }, {   94, 0x0000 }, {   94, 0x0000 },
  {   94, 0x0000 }, {   94, 0x0000 }, {   94, 0x0008 },
};
static const Summary16 hkscs2001_uni2indx_page241[5] = {
  /* 0x24100 */
  {   95, 0x0000 }, {   95, 0x0000 }, {   95, 0x0000 }, {   95, 0x0000 },
  {   95, 0x4000 },
};
static const Summary16 hkscs2001_uni2indx_page245[1] = {
  /* 0x24500 */
  {   96, 0x0020 },
};
static const Summary16 hkscs2001_uni2indx_page249[18] = {
  /* 0x24900 */
  {   97, 0x0000 }, {   97, 0x0000 }, {   97, 0x0000 }, {   97, 0x0000 },
  {   97, 0x0000 }, {   97, 0x0000 }, {   97, 0x0000 }, {   97, 0x0800 },
  {   98, 0x0000 }, {   98, 0x0000 }, {   98, 0x0000 }, {   98, 0x0000 },
  {   98, 0x0000 }, {   98, 0x0000 }, {   98, 0x0000 }, {   98, 0x0000 },
  /* 0x24a00 */
  {   98, 0x0000 }, {   98, 0x0008 },
};
static const Summary16 hkscs2001_uni2indx_page251[13] = {
  /* 0x25100 */
  {   99, 0x0000 }, {   99, 0x0000 }, {   99, 0x0000 }, {   99, 0x0000 },
  {   99, 0x0000 }, {   99, 0x0000 }, {   99, 0x0000 }, {   99, 0x0000 },
  {   99, 0x0000 }, {   99, 0x0000 }, {   99, 0x0000 }, {   99, 0x0000 },
  {   99, 0x2000 },
};
static const Summary16 hkscs2001_uni2indx_page256[10] = {
  /* 0x25600 */
  {  100, 0x0000 }, {  100, 0x0000 }, {  100, 0x0000 }, {  100, 0x0000 },
  {  100, 0x0000 }, {  100, 0x0000 }, {  100, 0x0000 }, {  100, 0x0000 },
  {  100, 0x0000 }, {  100, 0x0020 },
};
static const Summary16 hkscs2001_uni2indx_page25c[20] = {
  /* 0x25c00 */
  {  101, 0x0000 }, {  101, 0x0000 }, {  101, 0x0000 }, {  101, 0x0000 },
  {  101, 0x0000 }, {  101, 0x0000 }, {  101, 0x0000 }, {  101, 0x0000 },
  {  101, 0x0000 }, {  101, 0x0000 }, {  101, 0x0010 }, {  102, 0x0000 },
  {  102, 0x0000 }, {  102, 0x0000 }, {  102, 0x0000 }, {  102, 0x0000 },
  /* 0x25d00 */
  {  102, 0x0000 }, {  102, 0x0000 }, {  102, 0x0000 }, {  102, 0x0001 },
};
static const Summary16 hkscs2001_uni2indx_page26b[2] = {
  /* 0x26b00 */
  {  103, 0x0000 }, {  103, 0x0020 },
};
static const Summary16 hkscs2001_uni2indx_page26d[8] = {
  /* 0x26d00 */
  {  104, 0x0000 }, {  104, 0x0000 }, {  104, 0x0000 }, {  104, 0x0000 },
  {  104, 0x0000 }, {  104, 0x0000 }, {  104, 0x0000 }, {  104, 0x0010 },
};
static const Summary16 hkscs2001_uni2indx_page26f[12] = {
  /* 0x26f00 */
  {  105, 0x0000 }, {  105, 0x0000 }, {  105, 0x0000 }, {  105, 0x0000 },
  {  105, 0x0000 }, {  105, 0x0000 }, {  105, 0x0000 }, {  105, 0x0000 },
  {  105, 0x0000 }, {  105, 0x0000 }, {  105, 0x0000 }, {  105, 0x4000 },
};
static const Summary16 hkscs2001_uni2indx_page271[1] = {
  /* 0x27100 */
  {  106, 0x2000 },
};
static const Summary16 hkscs2001_uni2indx_page287[1] = {
  /* 0x28700 */
  {  107, 0x8000 },
};
static const Summary16 hkscs2001_uni2indx_page289[31] = {
  /* 0x28900 */
  {  108, 0x0000 }, {  108, 0x0000 }, {  108, 0x0000 }, {  108, 0x0000 },
  {  108, 0x0000 }, {  108, 0x0000 }, {  108, 0x0000 }, {  108, 0x0000 },
  {  108, 0x0000 }, {  108, 0x0000 }, {  108, 0x0000 }, {  108, 0x0000 },
  {  108, 0x0000 }, {  108, 0x0000 }, {  108, 0x0008 }, {  109, 0x0000 },
  /* 0x28a00 */
  {  109, 0x0000 }, {  109, 0x0000 }, {  109, 0x0000 }, {  109, 0x0004 },
  {  110, 0x0000 }, {  110, 0x0000 }, {  110, 0x0000 }, {  110, 0x0000 },
  {  110, 0x0000 }, {  110, 0x0000 }, {  110, 0x0000 }, {  110, 0x0000 },
  {  110, 0x0000 }, {  110, 0x0000 }, {  110, 0x0400 },
};
static const Summary16 hkscs2001_uni2indx_page28d[12] = {
  /* 0x28d00 */
  {  111, 0x0000 }, {  111, 0x0000 }, {  111, 0x0000 }, {  111, 0x0000 },
  {  111, 0x0000 }, {  111, 0x0000 }, {  111, 0x0000 }, {  111, 0x0000 },
  {  111, 0x0000 }, {  111, 0x0000 }, {  111, 0x0000 }, {  111, 0x0200 },
};
static const Summary16 hkscs2001_uni2indx_page299[5] = {
  /* 0x29900 */
  {  112, 0x0000 }, {  112, 0x0000 }, {  112, 0x0000 }, {  112, 0x0000 },
  {  112, 0x0080 },
};
static const Summary16 hkscs2001_uni2indx_page29c[8] = {
  /* 0x29c00 */
  {  113, 0x0000 }, {  113, 0x0000 }, {  113, 0x0000 }, {  113, 0x0000 },
  {  113, 0x0000 }, {  113, 0x0000 }, {  113, 0x0000 }, {  113, 0x0008 },
};
static const Summary16 hkscs2001_uni2indx_page2a1[28] = {
  /* 0x2a100 */
  {  114, 0x0080 }, {  115, 0x0000 }, {  115, 0x0000 }, {  115, 0x0000 },
  {  115, 0x0000 }, {  115, 0x0000 }, {  115, 0x0000 }, {  115, 0x0000 },
  {  115, 0x0000 }, {  115, 0x0000 }, {  115, 0x0000 }, {  115, 0x0000 },
  {  115, 0x0000 }, {  115, 0x0000 }, {  115, 0x0000 }, {  115, 0x0000 },
  /* 0x2a200 */
  {  115, 0x0000 }, {  115, 0x0000 }, {  115, 0x0000 }, {  115, 0x0000 },
  {  115, 0x0000 }, {  115, 0x0000 }, {  115, 0x0000 }, {  115, 0x0000 },
  {  115, 0x0000 }, {  115, 0x0000 }, {  115, 0x0000 }, {  115, 0x0400 },
};

static int
hkscs2001_wctomb (conv_t conv, unsigned char *r, ucs4_t wc, size_t n)
{
  if (n >= 2) {
    const Summary16 *summary = NULL;
    if (wc < 0x9f00) {
      if (wc < 0x6900) {
        if (wc >= 0x3500 && wc < 0x3560)
          summary = &hkscs2001_uni2indx_page35[(wc>>4)-0x350];
        else if (wc >= 0x3c00 && wc < 0x3ee0)
          summary = &hkscs2001_uni2indx_page3c[(wc>>4)-0x3c0];
        else if (wc >= 0x4000 && wc < 0x4080)
          summary = &hkscs2001_uni2indx_page40[(wc>>4)-0x400];
        else if (wc >= 0x4200 && wc < 0x42b0)
          summary = &hkscs2001_uni2indx_page42[(wc>>4)-0x420];
        else if (wc >= 0x4b00 && wc < 0x4c90)
          summary = &hkscs2001_uni2indx_page4b[(wc>>4)-0x4b0];
        else if (wc >= 0x4e00 && wc < 0x51b0)
          summary = &hkscs2001_uni2indx_page4e[(wc>>4)-0x4e0];
        else if (wc >= 0x5300 && wc < 0x5440)
          summary = &hkscs2001_uni2indx_page53[(wc>>4)-0x530];
        else if (wc >= 0x5700 && wc < 0x58e0)
          summary = &hkscs2001_uni2indx_page57[(wc>>4)-0x570];
        else if (wc >= 0x5a00 && wc < 0x5fd0)
          summary = &hkscs2001_uni2indx_page5a[(wc>>4)-0x5a0];
        else if (wc >= 0x6100 && wc < 0x6130)
          summary = &hkscs2001_uni2indx_page61[(wc>>4)-0x610];
        else if (wc >= 0x6500 && wc < 0x6590)
          summary = &hkscs2001_uni2indx_page65[(wc>>4)-0x650];
        else if (wc >= 0x6700 && wc < 0x6770)
          summary = &hkscs2001_uni2indx_page67[(wc>>4)-0x670];
      } else {
        if (wc >= 0x6900 && wc < 0x6a70)
          summary = &hkscs2001_uni2indx_page69[(wc>>4)-0x690];
        else if (wc >= 0x6c00 && wc < 0x6e00)
          summary = &hkscs2001_uni2indx_page6c[(wc>>4)-0x6c0];
        else if (wc >= 0x7000 && wc < 0x74c0)
          summary = &hkscs2001_uni2indx_page70[(wc>>4)-0x700];
        else if (wc >= 0x7600 && wc < 0x78f0)
          summary = &hkscs2001_uni2indx_page76[(wc>>4)-0x760];
        else if (wc >= 0x7a00 && wc < 0x7e70)
          summary = &hkscs2001_uni2indx_page7a[(wc>>4)-0x7a0];
        else if (wc >= 0x8200 && wc < 0x8300)
          summary = &hkscs2001_uni2indx_page82[(wc>>4)-0x820];
        else if (wc >= 0x8500 && wc < 0x8610)
          summary = &hkscs2001_uni2indx_page85[(wc>>4)-0x850];
        else if (wc >= 0x8800 && wc < 0x88a0)
          summary = &hkscs2001_uni2indx_page88[(wc>>4)-0x880];
        else if (wc >= 0x8b00 && wc < 0x8b90)
          summary = &hkscs2001_uni2indx_page8b[(wc>>4)-0x8b0];
        else if (wc >= 0x8e00 && wc < 0x8fd0)
          summary = &hkscs2001_uni2indx_page8e[(wc>>4)-0x8e0];
        else if (wc >= 0x9100 && wc < 0x9400)
          summary = &hkscs2001_uni2indx_page91[(wc>>4)-0x910];
        else if (wc >= 0x9700 && wc < 0x99f0)
          summary = &hkscs2001_uni2indx_page97[(wc>>4)-0x970];
      }
    } else {
      if (wc < 0x25600) {
        if (wc >= 0x9f00 && wc < 0x9fb0)
          summary = &hkscs2001_uni2indx_page9f[(wc>>4)-0x9f0];
        else if (wc >= 0x21400 && wc < 0x21440)
          summary = &hkscs2001_uni2indx_page214[(wc>>4)-0x2140];
        else if (wc >= 0x21900 && wc < 0x21990)
          summary = &hkscs2001_uni2indx_page219[(wc>>4)-0x2190];
        else if (wc >= 0x21d00 && wc < 0x21dc0)
          summary = &hkscs2001_uni2indx_page21d[(wc>>4)-0x21d0];
        else if (wc >= 0x22000 && wc < 0x22080)
          summary = &hkscs2001_uni2indx_page220[(wc>>4)-0x2200];
        else if (wc >= 0x22700 && wc < 0x22720)
          summary = &hkscs2001_uni2indx_page227[(wc>>4)-0x2270];
        else if (wc >= 0x23200 && wc < 0x23400)
          summary = &hkscs2001_uni2indx_page232[(wc>>4)-0x2320];
        else if (wc >= 0x23c00 && wc < 0x23c70)
          summary = &hkscs2001_uni2indx_page23c[(wc>>4)-0x23c0];
        else if (wc >= 0x24100 && wc < 0x24150)
          summary = &hkscs2001_uni2indx_page241[(wc>>4)-0x2410];
        else if (wc >= 0x24500 && wc < 0x24510)
          summary = &hkscs2001_uni2indx_page245[(wc>>4)-0x2450];
        else if (wc >= 0x24900 && wc < 0x24a20)
          summary = &hkscs2001_uni2indx_page249[(wc>>4)-0x2490];
        else if (wc >= 0x25100 && wc < 0x251d0)
          summary = &hkscs2001_uni2indx_page251[(wc>>4)-0x2510];
      } else {
        if (wc >= 0x25600 && wc < 0x256a0)
          summary = &hkscs2001_uni2indx_page256[(wc>>4)-0x2560];
        else if (wc >= 0x25c00 && wc < 0x25d40)
          summary = &hkscs2001_uni2indx_page25c[(wc>>4)-0x25c0];
        else if (wc >= 0x26b00 && wc < 0x26b20)
          summary = &hkscs2001_uni2indx_page26b[(wc>>4)-0x26b0];
        else if (wc >= 0x26d00 && wc < 0x26d80)
          summary = &hkscs2001_uni2indx_page26d[(wc>>4)-0x26d0];
        else if (wc >= 0x26f00 && wc < 0x26fc0)
          summary = &hkscs2001_uni2indx_page26f[(wc>>4)-0x26f0];
        else if (wc >= 0x27100 && wc < 0x27110)
          summary = &hkscs2001_uni2indx_page271[(wc>>4)-0x2710];
        else if (wc >= 0x28700 && wc < 0x28710)
          summary = &hkscs2001_uni2indx_page287[(wc>>4)-0x2870];
        else if (wc >= 0x28900 && wc < 0x28af0)
          summary = &hkscs2001_uni2indx_page289[(wc>>4)-0x2890];
        else if (wc >= 0x28d00 && wc < 0x28dc0)
          summary = &hkscs2001_uni2indx_page28d[(wc>>4)-0x28d0];
        else if (wc >= 0x29900 && wc < 0x29950)
          summary = &hkscs2001_uni2indx_page299[(wc>>4)-0x2990];
        else if (wc >= 0x29c00 && wc < 0x29c80)
          summary = &hkscs2001_uni2indx_page29c[(wc>>4)-0x29c0];
        else if (wc >= 0x2a100 && wc < 0x2a2c0)
          summary = &hkscs2001_uni2indx_page2a1[(wc>>4)-0x2a10];
      }
    }
    if (summary) {
      unsigned short used = summary->used;
      unsigned int i = wc & 0x0f;
      if (used & ((unsigned short) 1 << i)) {
        unsigned short c;
        /* Keep in 'used' only the bits 0..i-1. */
        used &= ((unsigned short) 1 << i) - 1;
        /* Add 'summary->indx' and the number of bits set in 'used'. */
        used = (used & 0x5555) + ((used & 0xaaaa) >> 1);
        used = (used & 0x3333) + ((used & 0xcccc) >> 2);
        used = (used & 0x0f0f) + ((used & 0xf0f0) >> 4);
        used = (used & 0x00ff) + (used >> 8);
        c = hkscs2001_2charset[summary->indx + used];
        r[0] = (c >> 8); r[1] = (c & 0xff);
        return 2;
      }
    }
    return RET_ILUNI;
  }
  return RET_TOOSMALL;
}
