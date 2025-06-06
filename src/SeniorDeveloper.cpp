// File: src/SeniorDeveloper.cpp
#include "SeniorDeveloper.hpp"
#include <iostream>

// Constructor: Initializes a SeniorDeveloper with a name and alias,
// passing them to the base Developer class constructor
SeniorDeveloper::SeniorDeveloper(const std::string& name, const std::string& aliasName)
    : Developer(name, aliasName) {}

// Implementation of the solve_problem method for SeniorDeveloper
void SeniorDeveloper::solve_problem() const {
    std::cout << "Solving a problem:" << std::endl;

    // Print the developer's details using the overloaded << operator
    std::cout << *this;

    // Simulate solving the problem with a confident message
    std::cout << "Ha, that was EZ!" << std::endl;

    // Call the static method to simulate drinking coffee after solving the problem
    Developer::drink_coffee();
}
