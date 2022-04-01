#include <stdio.h>
#include "operation.h"

int main(int argc, char* argv[]) {
    if(argc != 4) {
        printf("Error: Param cnt invalid.\n");
        return -1;
    }

    int result = 0;
    if('+' == argv[2][0]) {
        result = add(argv[1][0], argv[3][0]);
    }
    else if('-' == argv[2][0]) {
        result = sub(argv[1][0], argv[3][0]);
    }
    else {
        printf("Error: Operand invalid.\n");
        return -1;
    }

    printf("Result: %d\n", result);
    return 0;
}
