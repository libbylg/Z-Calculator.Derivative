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
# include "variable.h"

// Variable List Utilities

variable * * variable_list_initializer(variable * * list_){

    // initialize the variable list

    // [PARAMETER] [variable list]

    if(list_){
        size_t n = 0;
        while(list_[n]){
            free(list_[n]->symbol);
            free(list_[n]);
            n++;
        }
        free(list_);
    }
    list_ = malloc(sizeof(variable *));
    *list_ = NULL;
    return list_;

}

variable * * registerer(node * const node_, const char * const symbol_, variable * * list_){

    // look up the symbol in the variable list and if this symbol is
    // 1. already registered in the variable list : renew object's value
    // 2. not registered yet in the variable list : add it to the variable list and renew object's value

    // [PARAMETER] [object node], [symbol], [variable list]

    size_t n = 0;
    while(list_[n]){
        if(!strcmp(list_[n]->symbol, symbol_)){
            /* case 1 */
            node_->child_l = (node *)list_[n];
            return list_;
        }
        n++;
    }
    /* case 2 */
    list_ = realloc(list_, (n+2) * sizeof(variable *));
    list_[n] = malloc(sizeof(variable));
    list_[n]->symbol = malloc((strlen(symbol_)+1) * sizeof(char));
    strcpy(list_[n]->symbol, symbol_);
    list_[n+1] = NULL;
    node_->child_l = (node *)list_[n];
    return list_;

}
