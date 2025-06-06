/**
 * @file SeniorDeveloper.cpp
 * @brief Implementation of the SeniorDeveloper class.
 */

#include "SeniorDeveloper.hpp"
#include <iostream>

/**
 * @brief Constructor that initializes a SeniorDeveloper.
 * 
 * Passes the name and aliasName parameters to the base Developer class constructor.
 * 
 * @param name The real name of the senior developer.
 * @param aliasName The alias or nickname of the senior developer.
 */
SeniorDeveloper::SeniorDeveloper(const std::string& name, const std::string& aliasName)
    : Developer(name, aliasName) {}

/**
 * @brief Overrides the abstract solve_problem method.
 * 
 * Prints developer details, simulates solving a problem confidently,
 * and calls the static drink_coffee method.
 */
void SeniorDeveloper::solve_problem() const {
    std::cout << "Solving a problem:" << std::endl;

    /** Output developer's information using the stream insertion operator */
    std::cout << *this;

    /** Display a confident message after solving the problem */
    std::cout << "Ha, that was EZ!" << std::endl;

    /** Simulate drinking coffee after problem solving */
    Developer::drink_coffee();
}
