#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include "operation.h"

#define RESULT_SUCCESS 0
#define RESULT_FAILURE -1

typedef enum {
    OPERATOR_TYPE_NONE,
    OPERATOR_TYPE_INT,
    OPERATOR_TYPE_BIT,
} OPERATOR_TYPE;

typedef struct {
    const char input_param;
    int32_t (*func)(int32_t, int32_t);
    OPERATOR_TYPE type;
} OPERATOR_ATTR; 


int parse_operator(OPERATOR_ATTR* operation);
int parse_operand(
    char* argv[], const OPERATOR_TYPE operator_type,
    int32_t* left_operand, int32_t* right_operand);

/*
 *  Usage: Enter ther following param when execute this program.
 *      1st param: Left Operand (integer or hexadecimal)
 *      2nd param: Operator (one character)
 *      3rd param: Right Operand (integer or hexadecimal)
 *
 *  Operator type:
 *      TYPE_INT: +, -, *, /, %
 *      TYPE_BIT: < (left shift), > (right shift), &, |, ^
 *
 *  Rule:
 *      If Operator type is TYPE_INT, Operand is an integer value.
 *      If Operator type is TYPE_BIT, Operand is a hexadecimal value.
 */
int main(int argc, char* argv[]) {
    /*
     *  Input param count check.
     */
    for(int32_t i=1; i < argc; i++) {
        printf("Debug argv[%d]: %s\n", i, argv[i]);
    }
    if(argc != 4) {
        printf("Error: Param cnt invalid.\n");
        return -1;
    }
    
    /*
     *  Operator check.
     */
    OPERATOR_ATTR operator = {
        argv[2][0],
        NULL,
        OPERATOR_TYPE_NONE
    };
    if(parse_operator(&operator) != RESULT_SUCCESS) {
        return -1;
    }
    printf("Debug operand type: %d\n", operator.type);

    /*
     *  Operand check.
     */
    int32_t left_operand = 0;
    int32_t right_operand = 0;
    if(parse_operand(
        argv, operator.type, &left_operand, &right_operand) != RESULT_SUCCESS) {
        return -1;
    }
    printf("Debug left operand : %d, 0x%02x\n", left_operand, left_operand);
    printf("Debug right operand: %d, 0x%02x\n", right_operand, right_operand);

    /*
     *  Execute operation and print result.
     */
    const int32_t result = (*operator.func)(left_operand, right_operand);
    if(operator.type == OPERATOR_TYPE_INT) {
        printf("Result: %d\n", result);
    }
    else {
        printf("Result: %d, 0x%02x\n", result, result);
    }

    return 0;
}


int parse_operator(OPERATOR_ATTR* operator) {
    switch(operator->input_param) {
    case '+':
        operator->func = operate_add;
        operator->type = OPERATOR_TYPE_INT;
        break;
    case '-':
        operator->func = operate_sub;
        operator->type = OPERATOR_TYPE_INT;
        break;
    case '*':
        operator->func = operate_multi;
        operator->type = OPERATOR_TYPE_INT;
        break;
    case '/':
        operator->func = operate_div;
        operator->type = OPERATOR_TYPE_INT;
        break;
    case '%':
        operator->func = operate_mod;
        operator->type = OPERATOR_TYPE_INT;
        break;
    case '<':
        operator->func = operate_bit_lshift;
        operator->type = OPERATOR_TYPE_BIT;
        break;
    case '>':
        operator->func = operate_bit_rshift;
        operator->type = OPERATOR_TYPE_BIT;
        break;
    case '&':
        operator->func = operate_bit_and;
        operator->type = OPERATOR_TYPE_BIT;
        break;
    case '|':
        operator->func = operate_bit_or;
        operator->type = OPERATOR_TYPE_BIT;
        break;
    case '^':
        operator->func = operate_bit_invert;
        operator->type = OPERATOR_TYPE_BIT;
        break;
    default:
        printf("Error: Operand invalid.\n");
        return RESULT_FAILURE;
    }

    return RESULT_SUCCESS;
}


int parse_operand(
    char* argv[], const OPERATOR_TYPE operator_type,
    int32_t* left_operand, int32_t* right_operand) {
    if(operator_type == OPERATOR_TYPE_INT) {
        if(EOF == sscanf(argv[1], "%d", left_operand)) {
            printf("Error: Left value invalid.\n");
            return RESULT_FAILURE;
        }
        if(EOF == sscanf(argv[3], "%d", right_operand)) {
            printf("Error: Right value invalid.\n");
            return RESULT_FAILURE;
        }
    }
    else {
        if(EOF == sscanf(argv[1], "%x", left_operand)) {
            printf("Error: Left value invalid.\n");
            return RESULT_FAILURE;
        }
        if(EOF == sscanf(argv[3], "%x", right_operand)) {
            printf("Error: Right value invalid.\n");
            return RESULT_FAILURE;
        }
    } 

    return RESULT_SUCCESS;
}
