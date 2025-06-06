// File: src/JuniorDeveloper.cpp

#include "JuniorDeveloper.hpp"
#include <iostream>

// Constructor: initializes JuniorDeveloper by calling the base class constructor
JuniorDeveloper::JuniorDeveloper(const std::string& name, const std::string& aliasName)
    : Developer(name, aliasName) {}

// Implementation of the pure virtual function solve_problem for JuniorDeveloper
void JuniorDeveloper::solve_problem() const {
    std::cout << "Solving a problem:" << std::endl;

    // Use the overloaded << operator to print developer information
    std::cout << *this;

    // Print a message to simulate solving difficulty
    std::cout << "Puh, that was tough" << std::endl;

    // Call static method to simulate drinking coffee after solving the problem
    Developer::drink_coffee();
}
