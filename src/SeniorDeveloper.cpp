// Datei: src/SeniorDeveloper.cpp
#include "SeniorDeveloper.hpp"
#include <iostream>

SeniorDeveloper::SeniorDeveloper(const std::string& name, const std::string& aliasName)
    : Developer(name, aliasName) {}

void SeniorDeveloper::solve_problem() const {
    std::cout << "Solving a problem:" << std::endl;
    std::cout << *this;
    std::cout << "Ha, that was EZ!" << std::endl;
    Developer::drink_coffee();
}