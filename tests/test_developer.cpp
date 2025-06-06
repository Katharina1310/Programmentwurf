/**
 * @file test_developer.cpp
 * @brief Unit tests for the Developer class hierarchy using Google Test.
 */

#include <gtest/gtest.h>
#include "developer.hpp"
#include "JuniorDeveloper.hpp"

/**
 * @class DeveloperTest
 * @brief Test fixture class for testing Developer functionality.
 * 
 * Sets up a JuniorDeveloper instance for reuse in test cases.
 */
class DeveloperTest : public ::testing::Test {
protected:
    JuniorDeveloper dev{"Anikan Skywalker", "Darth Vader"};
};

/**
 * @brief Tests if the constructor initializes name, alias, and logo correctly.
 */
TEST_F(DeveloperTest, ConstructorInitializesCorrectly) {
    EXPECT_EQ(dev.get_name(), "Anikan Skywalker");
    EXPECT_EQ(dev.get_alias_name(), "Darth Vader");
    EXPECT_EQ(dev.get_logo(), "");
}

/**
 * @brief Tests loading a valid logo file successfully updates the logo string.
 */
TEST_F(DeveloperTest, LoadLogoValidFile) {
    dev.load_logo_from_file("Darth_Vader.txt");
    EXPECT_FALSE(dev.get_logo().empty());
}

/**
 * @brief Tests that loading a nonexistent logo file throws a runtime_error.
 */
TEST_F(DeveloperTest, LoadLogoInvalidFileThrows) {
    EXPECT_THROW(dev.load_logo_from_file("non_existent_logo.txt"), std::runtime_error);
}
