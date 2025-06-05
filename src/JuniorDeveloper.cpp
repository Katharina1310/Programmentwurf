// Datei: src/JuniorDeveloper.cpp
#include "JuniorDeveloper.hpp"
#include <iostream>

JuniorDeveloper::JuniorDeveloper(const std::string& name, const std::string& aliasName)
    : Developer(name, aliasName) {}

void JuniorDeveloper::solve_problem() const {
    std::cout << "Solving a problem:" << std::endl;
    std::cout << *this;
    std::cout << "Puh, that was tough" << std::endl;
    Developer::drink_coffee();
}