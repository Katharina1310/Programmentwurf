// File: include/SeniorDeveloper.hpp

#ifndef SENIORDEVELOPER_HPP
#define SENIORDEVELOPER_HPP

#include "Developer.hpp"

// SeniorDeveloper is a subclass of Developer
class SeniorDeveloper : public Developer {
public:
    // Constructor: initializes the SeniorDeveloper with a name and an alias
    SeniorDeveloper(const std::string& name, const std::string& aliasName);

    // Defines how a senior developer solves a problem
    void solve_problem() const override;
};

#endif
