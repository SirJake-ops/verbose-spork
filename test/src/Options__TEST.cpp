//
// Created by Jacob Pagan on 5/24/2025.
//

#include <gtest/gtest.h>
#include "../../include/Call.h"
#include "../include/TestObjectGenerators.h"


TEST(Options_generic_test, BasicAssertions) {
    //TODO: Create a vector of a particular option
    Call call;
    Generator<Call> generator(call, 10);
    EXPECT_EQ(generator.getVector().size(), 10);
}