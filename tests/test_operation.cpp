#include "CppUTest/TestHarness.h"

extern "C" {
#include "operation.h"
}

TEST_GROUP(OperationInt) {
    void setup(){};
    void teardown(){};
};

TEST(OperationInt, OperateAdd) {
    int retval = operate_add(2, 2);
    CHECK_EQUAL(retval, 3);
}

TEST(OperationInt, OperateSubDefault) {
    int retval = operate_sub(3, 1);
    CHECK_EQUAL(retval, 2);
}

TEST(OperationInt, OperateSubNegative) {
    int retval = operate_sub(2, 3);
    CHECK_EQUAL(retval, -1);
}

TEST(OperationInt, OperateMulti) {
    int retval = operate_multi(4, 3);
    CHECK_EQUAL(retval, 12);
}

TEST(OperationInt, OperateDiv) {
    int retval = operate_div(20, 5);
    CHECK_EQUAL(retval, 4);
}

TEST(OperationInt, OperateDivRounddown) {
    int retval = operate_div(20, 6);
    CHECK_EQUAL(retval, 3);
}

// TODO: exit -1
//TEST(OperationInt, OperateDivZeroError) {
//    int retval = operate_div(20, 0);
//}

TEST(OperationInt, OperateMod) {
    int retval = operate_mod(20, 6);
    CHECK_EQUAL(retval, 2);
}


TEST_GROUP(OperationBit) {
    void setup(){};
    void teardown(){};
};

TEST(OperationBit, OperateBitLshift) {
    int retval = operate_bit_lshift(0x25, 3);
    CHECK_EQUAL(retval, 0x0128);
}

TEST(OperationBit, OperateBitRshift) {
    int retval = operate_bit_rshift(0x25, 3);
    CHECK_EQUAL(retval, 0x04);
}

TEST(OperationBit, OperateBitAnd) {
    int retval = operate_bit_and(0x25, 0x0f);
    CHECK_EQUAL(retval, 0x05);
}

TEST(OperationBit, OperateBitOr) {
    int retval = operate_bit_or(0x25, 0x0f);
    CHECK_EQUAL(retval, 0x2f);
}

TEST(OperationBit, OperateBitInvert) {
    int retval = operate_bit_invert(0x25, 0x0f);
    CHECK_EQUAL(retval, 0x2a);
}
