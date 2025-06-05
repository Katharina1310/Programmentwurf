
// ===========================
// Datei: include/JuniorDeveloper.hpp
#ifndef JUNIORDEVELOPER_HPP
#define JUNIORDEVELOPER_HPP

#include "Developer.hpp"

class JuniorDeveloper : public Developer {
public:
    JuniorDeveloper(const std::string& name, const std::string& aliasName);
    void solve_problem() const override;
};

#endif