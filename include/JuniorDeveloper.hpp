// File: include/JuniorDeveloper.hpp

#ifndef JUNIORDEVELOPER_HPP
#define JUNIORDEVELOPER_HPP

#include "Developer.hpp"

// JuniorDeveloper is a subclass of Developer
class JuniorDeveloper : public Developer {
public:
    // Constructor: initializes the JuniorDeveloper with a name and an alias
    JuniorDeveloper(const std::string& name, const std::string& aliasName);

    // Represents how a junior developer solves a problem
    void solve_problem() const override;
};

#endif
