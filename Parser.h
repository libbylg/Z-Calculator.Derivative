/// 2025 Z·Calculator.Derivative

# pragma once

# include "_tree.h"
# include "variable.h"
# include "node_type.h"
# include "_Derivative.h"

// Parser Applications

void Parser_operator(char *);
void * * Parser(const char *, tree *);
