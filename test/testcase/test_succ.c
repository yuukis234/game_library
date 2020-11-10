#include <unity.h>
#include <unity_fixture.h>
#include "succ.h"

TEST_GROUP(Succ);
TEST_SETUP(Succ)
{}

TEST_TEAR_DOWN(Succ)
{}

TEST(Succ, succ_sample_test){
    TEST_ASSERT_EQUAL_INT(31, succ(30));
}