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

// Operation Precedence Definition

typedef enum oper_precedence oper_precedence;

enum oper_precedence {

    MIN_PREC, ADD_PREC, MUL_PREC, POW_PREC, MAX_PREC

};

// Object Type Definition

typedef struct object_type object_type;

struct object_type {

    char* name;

};

// Function Type Definition

typedef struct function_type function_type;

struct function_type {

    char* name;
    char* prefix;

};

// Operation Type Definition

typedef struct operation_type operation_type;

struct operation_type {

    char* name;
    char* prefix;
    char* infix;
    oper_precedence precedence;

};

// Node Type Utilities

# define type_check(Type,TypeName)  (!strcmp((Type)->name, TypeName))
