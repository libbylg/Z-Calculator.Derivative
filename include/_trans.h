/**
 * Copyright (c) 2025 Z·Math
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
# pragma once

// Forward Declaration

struct node;

// Tree Transformation (Value) Definition

typedef enum trans trans;
enum trans {

    SUCCEED = 0,
    PASS = 1,
    FAIL = 2,

};

// Tree Transformation Function Definition

typedef int (*trans_p)(struct node *);
typedef trans (*trans_f)(struct node *, const void * const *);

// __trans__ Definition

# define __trans__ __trans__
# define __trans___start(VALUE) trans __trans__ = VALUE
# define __trans___value __trans__

// · Definition

# define ·          /* serving for separating function names and arguments */
