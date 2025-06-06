// Include Google Test framework
#include <gtest/gtest.h>

// Include headers for Developer classes
#include "developer.hpp"
#include "JuniorDeveloper.hpp"

// Define a test fixture class for common setup
class DeveloperTest : public ::testing::Test {
protected:
    // Create a JuniorDeveloper object for use in the tests
    JuniorDeveloper dev{"Anikan Skywalker", "Darth Vader"};
};

// Test case: Ensure constructor sets name, alias name, and empty logo correctly
TEST_F(DeveloperTest, ConstructorInitializesCorrectly) {
    EXPECT_EQ(dev.get_name(), "Anikan Skywalker");        // Check if name is set correctly
    EXPECT_EQ(dev.get_alias_name(), "Darth Vader");       // Check if alias is set correctly
    EXPECT_EQ(dev.get_logo(), "");                        // Logo should be empty initially
}

// Test case: Load a valid logo file and ensure the logo is not empty
TEST_F(DeveloperTest, LoadLogoValidFile) {
    dev.load_logo_from_file("Darth_Vader.txt");           // Load existing file
    EXPECT_FALSE(dev.get_logo().empty());                 // Logo should now be loaded
}

// Test case: Attempt to load a nonexistent file and expect an exception
TEST_F(DeveloperTest, LoadLogoInvalidFileThrows) {
    EXPECT_THROW(
        dev.load_logo_from_file("non_existent_logo.txt"), // Load non-existing file
        std::runtime_error                                // Should throw std::runtime_error
    );
}
