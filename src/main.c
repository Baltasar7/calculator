#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include 

#define RESULT_SUCCESS 0
#define RESULT_FAILURE -1

typedef {
    OPERATOR_TYPE_NONE,
    OPERATOR_TYPE_INT,
    OPERATOR_TYPE_BIT,
} OPERATOR_TYPE;

typedef {
    const ;
    int32_t (*func)(int32_t, int32_t);
    OPERATOR_TYPE type;
} OPERATOR_ATTR; 


int parse_operator();
int parse_operand(
    char* argv[], const OPERATOR_TYPE operator_type,
    int32_t* left_operand, int32_t* right_operand);

int main(int argc, char* argv[]) {
    /*
     *  Input param count check.
     *  Notice: This Section is complete. No modification required.
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
        ,
        NULL,
        OPERATOR_TYPE_NONE
    };
    if(parse_operator() != RESULT_SUCCESS) {
        return -1;
    }
    printf("Debug operand type: %d\n", operator.type);

    /*
     *  Operand check.
     *  Notice: This Section is complete. No modification required.
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
     *  Notice: This Section is complete. No modification required.
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


int parse_operator() {
    switch() {
    case '+':
         = operate_add;
         = OPERATOR_TYPE_INT;
    case '&':
         = operate_bit_and;
         = OPERATOR_TYPE_BIT;
    default:
        printf("Error: Operand invalid.\n");
        return RESULT_FAILURE;
    }

    return RESULT_SUCCESS;
}


/*
 *  Notice: This function is complete. No modification required.
 */
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
