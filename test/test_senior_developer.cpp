/**
 * @file test_senior_developer.cpp
 * @brief Unit tests for the SeniorDeveloper class using Google Test.
 */

#include "developer.hpp"
#include "senior_developer.hpp"
#include <gtest/gtest.h> // include the gtest functions & macros

/**
 * @class SeniorDeveloperTest
 * @brief Test fixture class for testing SeniorDeveloper functionality.
 * 
 * Sets up a SeniorDeveloper instance for reuse in test cases.
 */
class SeniorDeveloperTest : public ::testing::Test {
protected:
    SeniorDeveloper dev{"Abu", "Aladdin's monkey"};
};

/**
 * @brief Tests if the constructor initializes name, alias, and logo correctly.
 */
TEST_F(SeniorDeveloperTest, ConstructorInitializesCorrectly) {
    EXPECT_EQ(dev.get_name(), "Abu");
    EXPECT_EQ(dev.get_alias_name(), "Aladdin's monkey");
    EXPECT_EQ(dev.get_logo(), "");
}

/**
 * @brief Tests loading a valid logo file successfully updates the logo string.
 */
TEST_F(SeniorDeveloperTest, LoadLogoValidFile) {
    dev.load_logo_from_file("Abu.txt");
    EXPECT_FALSE(dev.get_logo().empty());
}

/**
 * @brief Tests that loading a nonexistent logo file throws a runtime_error.
 */
TEST_F(SeniorDeveloperTest, LoadLogoInvalidFileThrows) {
    EXPECT_THROW(dev.load_logo_from_file("non_existent_logo.txt"), std::runtime_error);
}

/**
 * @brief Tests that loading an empty filename throws an invalid_argument exception.
 */
TEST_F(SeniorDeveloperTest, LoadLogoEmptyFilenameThrows) {
    EXPECT_THROW(dev.load_logo_from_file(""), std::invalid_argument);
}
