/**
 * @file utf16le.h
 * @brief UTF-16LE
 * @copyright Copyright (C) 1999-2001, 2008, 2016 Free Software Foundation, Inc.
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

#ifndef _UTF16LE_H_
#define _UTF16LE_H_

#include "reiconv_defines.h"

/* Specification: RFC 2781 */

static int utf16le_mbtowc(conv_t conv, ucs4_t *pwc, const unsigned char *s, size_t n)
{
    int count = 0;
    if (n >= 2)
    {
        ucs4_t wc = s[0] + (s[1] << 8);
        if (wc >= 0xd800 && wc < 0xdc00)
        {
            if (n >= 4)
            {
                ucs4_t wc2 = s[2] + (s[3] << 8);
                if (!(wc2 >= 0xdc00 && wc2 < 0xe000))
                    goto ilseq;
                *pwc = 0x10000 + ((wc - 0xd800) << 10) + (wc2 - 0xdc00);
                return count + 4;
            }
        }
        else if (wc >= 0xdc00 && wc < 0xe000)
        {
            goto ilseq;
        }
        else
        {
            *pwc = wc;
            return count + 2;
        }
    }
    return RET_TOOFEW(count);

ilseq:
    return RET_SHIFT_ILSEQ(count);
}

static int utf16le_wctomb(conv_t conv, unsigned char *r, ucs4_t wc, size_t n)
{
    if (!(wc >= 0xd800 && wc < 0xe000))
    {
        if (wc < 0x10000)
        {
            if (n >= 2)
            {
                r[0] = (unsigned char)wc;
                r[1] = (unsigned char)(wc >> 8);
                return 2;
            }
            else
                return RET_TOOSMALL;
        }
        else if (wc < 0x110000)
        {
            if (n >= 4)
            {
                ucs4_t wc1 = 0xd800 + ((wc - 0x10000) >> 10);
                ucs4_t wc2 = 0xdc00 + ((wc - 0x10000) & 0x3ff);
                r[0] = (unsigned char)wc1;
                r[1] = (unsigned char)(wc1 >> 8);
                r[2] = (unsigned char)wc2;
                r[3] = (unsigned char)(wc2 >> 8);
                return 4;
            }
            else
                return RET_TOOSMALL;
        }
    }
    return RET_ILUNI;
}

#endif /* _UTF16LE_H_ */
