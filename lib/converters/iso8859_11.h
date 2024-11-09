/**
 * @file iso8859_11.h
 * @brief ISO-8859-11
 * @copyright Copyright (C) 1999-2004, 2016 Free Software Foundation, Inc.
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

#ifndef _ISO8859_11_H_
#define _ISO8859_11_H_

#include "reiconv_defines.h"

static int iso8859_11_mbtowc(conv_t conv, ucs4_t *pwc, const unsigned char *s, size_t n)
{
    unsigned char c = *s;
    if (c < 0xa1)
    {
        *pwc = (ucs4_t)c;
        return 1;
    }
    else if (c <= 0xfb && !(c >= 0xdb && c <= 0xde))
    {
        *pwc = (ucs4_t)(c + 0x0d60);
        return 1;
    }
    return RET_ILSEQ;
}

static int iso8859_11_wctomb(conv_t conv, unsigned char *r, ucs4_t wc, size_t n)
{
    if (wc < 0x00a1)
    {
        *r = wc;
        return 1;
    }
    else if (wc >= 0x0e01 && wc <= 0x0e5b && !(wc >= 0x0e3b && wc <= 0x0e3e))
    {
        *r = wc - 0x0d60;
        return 1;
    }
    return RET_ILUNI;
}

#endif /* _ISO8859_11_H_ */
