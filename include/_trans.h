/// 2025 Z·Calculator.Derivative

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
typedef trans (*trans_f)(struct node *, void * *);

// __trans__ Definition

# define __trans__ __trans__
# define __trans___start(VALUE) trans __trans__ = VALUE
# define __trans___value __trans__

// · Definition

# define ·          /* serving for separating function names and arguments */
