/// 2025 Z·Calculator.Derivative

# pragma once

// Forward Declaration

struct variable;
struct node;

// Tree Definition

typedef struct tree tree;
struct tree {

    struct node * root;
    struct variable * * variable_list;          /* end with NULL */

};
