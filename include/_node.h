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

// Node Category Definition

typedef enum node_category node_category;

enum node_category {
    OBJECT,
    FUNCTION,
    OPERATION,
};

// Node Catagory Substitute

# define OBJECT_s           "0"
# define FUNCTION_s         "1"
# define OPERATION_s        "2"

// Node Definition

typedef struct node node;

struct node {

    // [REMARK] Objects' left child nodes "represent" their values(string or variable).

    node_category category;
    const void* type;     /* case to (object_type *), (function_type *) or (operation_type *) */
    struct node* parent;  /* cast to (tree *) for root node */
    struct node* child_l; /* cast to other pointer types for objects */
    struct node* child_r;
};

// __node__ Definition

# define __parent__     __parent__
# define __index__      __index__
# define __node__       (!__index__ ? __parent__->child_l : __parent__->child_r)

# define __node___record(Node) \
    node * const __parent__ = Node->parent; \
    const int __index__ = node_index(Node)

# define __node___assign(NodeValue) \
    do{ \
        if(!__index__){ \
            __parent__->child_l = NodeValue; \
        } else{ \
            __parent__->child_r = NodeValue; \
        } \
    } while(0)

// Node Utility

# define node_index(Node)   (Node == Node->parent->child_r)
