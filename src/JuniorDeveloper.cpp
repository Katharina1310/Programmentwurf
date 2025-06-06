/**
 * @file JuniorDeveloper.cpp
 * @brief Implementation of the JuniorDeveloper class.
 */

#include "JuniorDeveloper.hpp"
#include <iostream>

/**
 * @brief Constructor that initializes a JuniorDeveloper.
 * 
 * Calls the base Developer class constructor with the given name and alias.
 * 
 * @param name The real name of the junior developer.
 * @param aliasName The alias or nickname of the junior developer.
 */
JuniorDeveloper::JuniorDeveloper(const std::string& name, const std::string& aliasName)
    : Developer(name, aliasName) {}

/**
 * @brief Overrides the pure virtual solve_problem method.
 * 
 * Prints developer details, simulates a tough problem solving,
 * and calls the static drink_coffee method.
 */
void JuniorDeveloper::solve_problem() const {
    std::cout << "Solving a problem:" << std::endl;

    // Output developer's information using the overloaded stream operator
    std::cout << *this;

    // Display a message indicating difficulty
    std::cout << "Puh, that was tough" << std::endl;

    // Simulate drinking coffee after problem solving
    Developer::drink_coffee();
}
