#include <stdio.h>
#include <stdlib.h>

int operate_add(int left, int right) {
    return left + right;
}

int operate_sub(int left, int right) {
    return left - right;
}

int operate_multi(int left, int right) {
    return left * right;
}

int operate_div(int left, int right) {
    if(right == 0) {
        printf("Error: Division by zero.\n");
        exit(-1);
    }
    return left / right;
}

int operate_mod(int left, int right) {
    return left % right;
}

int operate_bit_lshift(int left, int right) {
    return left << right;
}

int operate_bit_rshift(int left, int right) {
    return left >> right;
}

int operate_bit_and(int left, int right) {
    return left & right;
}

int operate_bit_or(int left, int right) {
    return left | right;
}

int operate_bit_invert(int left, int right) {
    return left ^ right;
}
