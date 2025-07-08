/// 2025 Z·Calculator.Derivative

# pragma once

# include <string.h>
# include "_node_type.h"

// Node Type Utilities

function_type * search_function_type(const char *, function_type * const *);
operation_type * search_operation_type(const char *, operation_type * const *);
