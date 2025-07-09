/// 2025 Z·Calculator.Derivative

# pragma once

// Operation Precedence Definition

typedef enum oper_precedence oper_precedence;
enum oper_precedence {

    MIN_PREC, ADD_PREC, MUL_PREC, POW_PREC, MAX_PREC

};

// Object Type Definition

typedef struct object_type object_type;
struct object_type {

    char * name;

};

// Function Type Definition

typedef struct function_type function_type;
struct function_type {

    char * name;
    char * prefix;

};

// Operation Type Definition

typedef struct operation_type operation_type;
struct operation_type {

    char * name;
    char * prefix;
    char * infix;
    oper_precedence precedence;

};

// Node Type Utilities

# define type_check(Type,TypeName)  (!strcmp((Type)->name, TypeName))
