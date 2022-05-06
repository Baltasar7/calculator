#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include "operation.h"

int main(int argc, char* argv[]) {
    for(int32_t i=1; i < argc; i++) {
        printf("Debug param[%d]: %s\n", i, argv[i]);
    }

    if(argc != 4) {
        printf("Error: Param cnt invalid.\n");
        return -1;
    }

    int32_t left_val = 0;
    int32_t right_val = 0;
    if(EOF == sscanf(argv[1], "%d", &left_val)) {
        printf("Error: Left value invalid.\n");
        return -1;
    }
    if(EOF == sscanf(argv[3], "%d", &right_val)) {
        printf("Error: Right value invalid.\n");
        return -1;
    }

    char operator = argv[2][0];
    int32_t result = 0;
    switch(operator) {
    case '+':
        result = operate_add(left_val, right_val);
        break;
    case '-':
        result = operate_sub(left_val, right_val);
        break;
    case '*':
        result = operate_multi(left_val, right_val);
        break;
    case '/':
        result = operate_div(left_val, right_val);
        break;
    case '%':
        result = operate_mod(left_val, right_val);
        break;
    default:
        printf("Error: Operand invalid.\n");
        return -1;
    }

    printf("Result: %d\n", result);
    return 0;
}
