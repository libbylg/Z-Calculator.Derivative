/// 2025 Z·Calculator.Derivative

# pragma once

// Node Category Definition

typedef enum node_category node_category;
enum node_category {

	OBJECT, FUNCTION, OPERATION

};

// Node Definition

typedef struct node node;
struct node {

    // [REMARK] Leaf nodes' left child nodes "represent" their values(string/constant/variable).

    node_category category;
    const void * type;              /* case to (object_type *), (function_type *) or (operation_type *) */
    struct node * parent;           /* cast to (tree *) for root node */
    struct node * child_l;          /* cast to other pointer types for object nodes */
    struct node * child_r;

};

// __node__ Definition

# define __parent__     __parent__
# define __index__      __index__
# define __node__       (!__index__ ? __parent__->child_l : __parent__->child_r)

# define __node___record(Node) \
    node * const __parent__ = Node->parent; \
    const int __index__ = node_index(Node);

# define __node___assign(NodeValue) \
    do{ \
        if(!__index__){ \
            __parent__->child_l = NodeValue; \
        } else{ \
            __parent__->child_r = NodeValue; \
        } \
    } while(0)

// Code Optimization

# define OBJECT_s           "0"
# define FUNCTION_s         "1"
# define OPERATION_s        "2"
# define node_index(Node)   (Node == Node->parent->child_r)
