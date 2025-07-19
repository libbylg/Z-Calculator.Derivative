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
# include "node_type.h"

// Node Type Utilities

const function_type* search_function_type(const char* const prefix_, const function_type* const * const list_) {

    // search for the function type by its prefix
    // [REMARK] Return NULL when the function type does not exist in the function type list.

    // [PARAMETER] [prefix], [function type list]

    for (int i = 0; list_[i]; i++) {
        if (!strcmp(list_[i]->prefix, prefix_)) {
            return list_[i];
        }
    }
    return NULL;

}

const operation_type* search_operation_type(const char* const prefix_, const operation_type* const * const list_) {

    // search for the operation type by its prefix
    // [REMARK] Return NULL when the operation type does not exist in the operation type list.

    // [PARAMETER] [prefix], [operation type list]

    for (int i = 0; list_[i]; i++) {
        if (!strcmp(list_[i]->prefix, prefix_)) {
            return list_[i];
        }
    }
    return NULL;

}
