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

# include <stdlib.h>
# include <string.h>
# include "_node_type.h"
# include "_tree.h"
# include "_trans.h"
# include "node.h"

// Tree Transformation Utilities

const void * const * format_subtree(node *, int, const void * const *, const node *);
void duplicate_subtree(node *, int, const node *);
void remove_subtree(node *);

// Tree Transformation Applications

trans trans_format(node *, const void * const *);
trans trans_format_p(node *, const void * const *);
trans trans_invoke(node *, const void * const *);
trans trans_single(node *, const void * const *);
trans trans_utmost(node *, const void * const *);
