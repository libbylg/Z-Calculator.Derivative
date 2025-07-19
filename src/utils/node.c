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

# include "node.h"

// Node Utilities

node* node_position(node* node_, const char* sequence_) {

    // use datum node and positioning sequence to position another node

    // [PARAMETER] [datum node], [positioning sequence]

    // [LIST] positioning sequence
    // 'l' left child node
    // 'r' right child node
    // other character will end the sequence and then return it

    while (*sequence_) {
        switch (*sequence_++) {
            case 'l':
                node_ = node_->child_l;
                break;
            case 'r':
                node_ = node_->child_r;
                break;
        }
    }
    return node_;

}

const node* node_position_c(const node* node_, const char* sequence_) {

    // use datum node(const) and positioning sequence to position another node(const)

    // [PARAMETER] [datum node], [positioning sequence]

    // [LIST] positioning sequence
    // 'l' left child node
    // 'r' right child node
    // other character will end the sequence and then return it

    while (*sequence_) {
        switch (*sequence_++) {
            case 'l':
                node_ = node_->child_l;
                break;
            case 'r':
                node_ = node_->child_r;
                break;
        }
    }
    return node_;

}
