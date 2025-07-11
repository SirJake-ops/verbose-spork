//
// Created by Jacob Pagan on 5/24/2025.
//

#include <gtest/gtest.h>
#include "../../include/Call.h"
#include "../include/TestObjectGenerators.h"


TEST(Options_generic_test, BasicAssertions) {
    //Generate a vector of 10 Call options
    Call call{};
    Generator<Call> call_generator(call, 10);
    EXPECT_EQ(call_generator.getVector().size(), 10);

    //Generate a vector of 10 Put options
    Put put{};
    Generator<Put> put_generator(put, 10);
    EXPECT_EQ(put_generator.getVector().size(), 10);
}

TEST(Options_Constructor_Test, BasicAssertions) {
    Generator<Call> call_option;
    EXPECT_NE(call_option.getOption().get_rfr(), 0.0);
    EXPECT_NE(call_option.getOption().get_time_to_expire(), 0.0);

    Generator<Call> put_option;
    EXPECT_NE(put_option.getOption().get_rfr(), 0.0);
    EXPECT_NE(put_option.getOption().get_time_to_expire(), 0.0);
}

