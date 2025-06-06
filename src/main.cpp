// File: src/main.cpp

#include <iostream>
#include <vector>
#include <memory>
#include "JuniorDeveloper.hpp"
#include "SeniorDeveloper.hpp"

int main() {
    // Create a vector to hold shared pointers to Developer objects
    std::vector<std::shared_ptr<Developer>> devs;

    // Dynamically create a SeniorDeveloper and a JuniorDeveloper
    auto senior = std::make_shared<SeniorDeveloper>("Abu", "Aladdin's monkey");
    auto junior = std::make_shared<JuniorDeveloper>("Anakin Skywalker", "Darth Vader");

    try {
        // Load logos for both developers from files
        senior->load_logo_from_file("Abu.txt");
        junior->load_logo_from_file("Darth_Vader.txt");
    } catch (const std::runtime_error& e) {
        // If any logo file fails to load, print the error message
        std::cerr << e.what() << std::endl;
    }

    // Add the developers to the vector
    devs.push_back(senior);
    devs.push_back(junior);

    // Iterate over the vector and have each developer solve a problem
    for (const auto& dev : devs) {
        dev->solve_problem();
    }

    // Wait for user input before closing the program
    std::cout << "\nPress Enter to exit...";
    std::cin.get();

    return 0;
}
