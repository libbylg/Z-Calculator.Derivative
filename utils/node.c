/// 2025 Z·Calculator.Derivative

# include "node.h"

// Node Utility

node * node_position(node * node_, const char * sequence_){

    // use datum node and positioning sequence to position another node
    // [LIST] positioning sequence
    // 'l' left child node
    // 'r' right child node
    // other character will end the sequence and then return it

    while(*sequence_){
        switch(*sequence_++){
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

const node * node_position_c(const node * node_, const char * sequence_){

    // use datum node and positioning sequence to position another node
    // [LIST] positioning sequence
    // 'l' left child node
    // 'r' right child node
    // other character will end the sequence and then return it

    while(*sequence_){
        switch(*sequence_++){
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
