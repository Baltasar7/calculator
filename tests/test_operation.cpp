#include "CppUTest/TestHarness.h"

extern "C" {
#include "operation.h"
}

TEST_GROUP(operation) {
    void setup(){};
    void teardown(){};
};

TEST(operation, OneColumnAddOperation) {
    int retval = add(1, 2);
    CHECK_EQUAL(retval, 3);
}
