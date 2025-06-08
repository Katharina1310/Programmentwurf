/** 
 * @file test_junior_developer.cpp
 * @brief Unit tests for the JuniorDeveloper class using Google Test.
 */
#include "developer.hpp"
#include "junior_developer.hpp"
#include <gtest/gtest.h> // include the gtest functions & macros

/**
 * @class JuniorDeveloperTest
 * @brief Test fixture class for testing JuniorDeveloper functionality.
 * 
 * Sets up a JuniorDeveloper instance for reuse in test cases.
 */
class JuniorDeveloperTest : public ::testing::Test {
protected:
    JuniorDeveloper dev{"Anikan Skywalker", "Darth Vader"};
};

/**
 * @brief Tests if the constructor initializes name, alias, and logo correctly.
 */
TEST_F(JuniorDeveloperTest, ConstructorInitializesCorrectly) {
    EXPECT_EQ(dev.get_name(), "Anikan Skywalker");
    EXPECT_EQ(dev.get_alias_name(), "Darth Vader");
    EXPECT_EQ(dev.get_logo(), "");
}

/**
 * @brief Tests loading a valid logo file successfully updates the logo string.
 */
TEST_F(JuniorDeveloperTest, LoadLogoValidFile) {
    dev.load_logo_from_file("Darth_Vader.txt");
    EXPECT_FALSE(dev.get_logo().empty());
}

/**
 * @brief Tests that loading a nonexistent logo file throws a runtime_error.
 */
TEST_F(JuniorDeveloperTest, LoadLogoInvalidFileThrows) {
    EXPECT_THROW(dev.load_logo_from_file("non_existent_logo.txt"), std::runtime_error);
}

/**
 * @brief Tests that loading an empty filename throws an invalid_argument exception.
 */
TEST_F(JuniorDeveloperTest, LoadLogoEmptyFilenameThrows) {
    EXPECT_THROW(dev.load_logo_from_file(""), std::invalid_argument);
}
