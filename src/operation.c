#include <stdio.h>
#include <stdlib.h>

int32_t operate_add(int32_t left, int32_t right) {
    return left + right;
}

int32_t operate_sub(int32_t left, int32_t right) {
    return left - right;
}

int32_t operate_multi(int32_t left, int32_t right) {
    return left * right;
}

int32_t operate_div(int32_t left, int32_t right) {
    if(right == 0) {
        printf("Error: Division by zero.\n");
        exit(-1);
    }
    return left / right;
}

int32_t operate_mod(int32_t left, int32_t right) {
    return left % right;
}

int32_t operate_bit_lshift(int32_t left, int32_t right) {
    return left << right;
}

int32_t operate_bit_rshift(int32_t left, int32_t right) {
    return left >> right;
}

int32_t operate_bit_and(int32_t left, int32_t right) {
    return left & right;
}

int32_t operate_bit_or(int32_t left, int32_t right) {
    return left | right;
}

int32_t operate_bit_invert(int32_t left, int32_t right) {
    return left ^ right;
}
