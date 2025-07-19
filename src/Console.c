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
# include "Console.h"

// Buffer

# define LEN_INPUT 9999

// Z·Calculator.Derivative Console

int main(void){

    double time;
    char * input = NULL;
    tree * Main = malloc(sizeof(tree));
    Main->root = calloc(1, sizeof(node));
    Main->root->category = FUNCTION;
    Main->root->type = &Root;
    Main->root->parent = (node *)Main;
    Main->root->child_l = NULL;
    Main->variable_list = NULL;
    Derivative_initializer();
    PRINT_CLS;
    while(1){
        print("\n>> ");
        /* Initializer */
        remove_subtree(Main->root->child_l);
        Main->root->child_l = calloc(1, sizeof(node));
        Main->root->child_l->category = OBJECT;
        Main->root->child_l->type = &Real;
        Main->root->child_l->parent = Main->root;
        Main->variable_list = variable_list_initializer(Main->variable_list);
        /* Input */
        free(input);
        input = calloc(LEN_INPUT, sizeof(char));
        input[0] = '(';
        scanf("%s", input + 1);
        input[strlen(input)] = ')';
        /* Parser */
        Parser_operator(input);
        trans_format(Main->root->child_l, Parser(input, Main));
        /* Calculator */
        time = clock();
        Derivative_calculator(Main->root);
        trans_utmost(Main->root->child_l, (const void * *)E_utmost_sequence);
        time = (clock() - time) / CLOCKS_PER_SEC;
        /* Printer */
        Print_s(Main->root);
        printf("\n\n [TIME] %.3f秒\n\n", time);
    }
    return 0;

}
