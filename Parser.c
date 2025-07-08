/// 2025 Z·Calculator.Derivative

# include "Parser.h"

// Functional Macros

# define string_check(String,StaticString) (!strncmp(String, StaticString, strlen(StaticString)))
# define string_cover(String,StaticString) strncpy(String, StaticString, strlen(StaticString))

// Parser Utilities

int len_sequence(void * * const sequence_, const void * const end_){

    // measure the length of the sequence

    int _length = 0;
    while(sequence_[_length] != end_){
        _length++;
    }
    return _length;

}

void string_shift(char * const string_, const size_t point_, const size_t length_){

    // right-shift the substring starting from start point by a given length
    // [PARAMETER] [string], [start point], [length]

    for(size_t i = strlen(string_) + length_ - 1; i >= point_ + length_; i--){
        string_[i] = string_[i-length_];
    }

}

size_t left_bracket_index(const char * const input_, size_t index_){

    // find the nearest left bracket(or comma)'s index
    // [REMARK] If there's no nearest left bracket, return -1

    int layer = 0;
    while(layer >= 0 && --index_ >= 0){
        if(layer == 0 && input_[index_] == ','){
            return index_;
        } else if(input_[index_] == '('){
            layer--;
        } else if(input_[index_] == ')'){
            layer++;
        }
    }
    return index_;

}

size_t right_bracket_index(const char * const input_, size_t index_){

    // find the nearest right bracket(or comma)'s index
    // [REMARK] If there's no nearest right bracket, return strlen(input_)

    int layer = 0;
    size_t length = strlen(input_);
    while(layer >= 0 && ++index_ < length){
        if(layer == 0 && input_[index_] == ','){
            return index_;
        } else if(input_[index_] == '('){
            layer++;
        } else if(input_[index_] == ')'){
            layer--;
        }
    }
    return index_;

}

int if_number(const char * string_){

    // check whether the string is a number

    do{
        if((*string_ < '0' || *string_ > '9') && *string_ != '.' && *string_ != '-'){
            return 0;
        }
    } while(*(++string_));
    return 1;

}

// Parser Applications

void Parser_operator(char * const input_){

    // convert operators to binary functions

    for(oper_precedence prec = MIN_PREC; prec < MAX_PREC; prec++){
        for(int n = 0; n < 6; n++){
            if(operation_list[n]->precedence == prec){
                for(size_t i = strlen(input_) - 1; i > 0; i--){
                    if(string_check(input_+i, operation_list[n]->infix)){
                        size_t index;
                        index = left_bracket_index(input_, i);
                        string_shift(input_, index+1, strlen(operation_list[n]->prefix)+1);
                        string_cover(input_+index+1, operation_list[n]->prefix);
                        string_cover(input_+index+strlen(operation_list[n]->prefix)+1, "(");
                        index = right_bracket_index(input_, i+strlen(operation_list[n]->prefix)+1);
                        string_shift(input_, index, 1);
                        string_cover(input_+index, ")");
                        input_[i+=(strlen(operation_list[n]->prefix)+1)] = ',';
                    }
                }
            }
        }
    }

}

void * * Parser(const char * const input_, tree * tree_){

    // convert the input into a generation sequence
    // [REMARK] The last non-'\0' character is definitely ')' unless there's only an object.

    int n;
    if(input_[strlen(input_)-1] == ')'){
        size_t start_index = 0;
        while(input_[start_index++] != '('){}
        if(string_check(input_, "(")){
            char * content = malloc((strlen(input_)-1)*sizeof(char));
            strncpy(content, input_+1, strlen(input_)-2);
            content[strlen(input_)-start_index-1] = '\0';
            void * * _sequence = Parser(content, tree_);
            free(content);
            return _sequence;
        } else{
            /* check the prefix */
            char * prefix = calloc(start_index, sizeof(char));
            strncpy(prefix, input_, start_index-1);
            prefix[start_index-1] = '\0';
            if(search_function_type(prefix, function_list)){
                char * content = calloc((strlen(input_)-start_index), sizeof(char));
                strncpy(content, input_+start_index, strlen(input_)-start_index-1);
                content[strlen(input_)-start_index-1] = '\0';
                void * * content_sequence = Parser(content, tree_);
                int length = len_sequence(content_sequence, &Parser_Primer);
                void * * _sequence = calloc((length+3), sizeof(void *));
                _sequence[0] = FUNCTION_s;
                _sequence[1] = search_function_type(prefix, function_list);
                for(n = 2; n < length + 2; n++){
                    _sequence[n] = content_sequence[n-2];
                }
                _sequence[n] = &Parser_Primer;
                free(prefix);
                free(content);
                free(content_sequence);
                return _sequence;
            } else{
                size_t mid_index = left_bracket_index(input_, strlen(input_)-1);
                char * content_1 = calloc((mid_index-start_index+1),sizeof(char));
                char * content_2 = calloc((strlen(input_)-mid_index-1),sizeof(char));
                strncpy(content_1, input_+start_index, mid_index-start_index);
                content_1[mid_index-start_index] = '\0';
                strncpy(content_2, input_+mid_index+1, strlen(input_)-mid_index-2);
                content_2[strlen(input_)-mid_index-2] = '\0';
                void * * content_sequence_1 = Parser(content_1, tree_);
                int length_1 = len_sequence(content_sequence_1, &Parser_Primer);
                void * * content_sequence_2 = Parser(content_2, tree_);
                int length_2 = len_sequence(content_sequence_2, &Parser_Primer);
                void * * _sequence = calloc((length_1+length_2+3),sizeof(void *));
                _sequence[0] = OPERATION_s;
                _sequence[1] = search_operation_type(prefix, operation_list);
                for(n = 2; n < length_1 + 2; n++){
                    _sequence[n] = content_sequence_1[n-2];
                }
                for(; n < length_1 + length_2 + 2; n++){
                    _sequence[n] = content_sequence_2[n-length_1-2];
                }
                _sequence[n] = &Parser_Primer;
                free(prefix);
                free(content_1);
                free(content_2);
                free(content_sequence_1);
                free(content_sequence_2);
                return _sequence;
            }
        }
    } else if(if_number(input_)){
        char * value = calloc((strlen(input_)+1), sizeof(char));
        strcpy(value, input_);
        void * * _sequence = calloc(4, sizeof(void *));
        _sequence[0] = OBJECT_s;
        _sequence[1] = &Real;
        _sequence[2] = value;
        _sequence[3] = &Parser_Primer;
        return _sequence;
    } else{
        node * _node_ = calloc(1, sizeof(node));
        _node_->category = OBJECT;
        _node_->type = &Variable;
        tree_->variable_list = registerer(_node_, input_, tree_->variable_list);
        void * * const _sequence = calloc(5, sizeof(void *));
        _sequence[0] = OBJECT_s;
        _sequence[1] = &Variable;
        _sequence[2] = NULL;
        _sequence[3] = _node_;
        _sequence[4] = &Parser_Primer;
        return _sequence;
    }

}
