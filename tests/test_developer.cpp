#include <gtest/gtest.h>
#include "developer.hpp"
#include "JuniorDeveloper.hpp"

class DeveloperTest : public ::testing::Test {
protected:
    JuniorDeveloper dev{"Anikan Skywalker", "Darth Vader"};
};

TEST_F(DeveloperTest, ConstructorInitializesCorrectly) {
    EXPECT_EQ(dev.get_name(), "Anikan Skywalker");
    EXPECT_EQ(dev.get_alias_name(), "Darth Vader");
    EXPECT_EQ(dev.get_logo(), "");
}

TEST_F(DeveloperTest, LoadLogoValidFile) {
    dev.load_logo_from_file("Darth_Vader.txt");
    EXPECT_FALSE(dev.get_logo().empty());
}

TEST_F(DeveloperTest, LoadLogoInvalidFileThrows) {
    EXPECT_THROW(dev.load_logo_from_file("non_existent_logo.txt"), std::runtime_error);
}
