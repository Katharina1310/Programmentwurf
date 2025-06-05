// Datei: include/SeniorDeveloper.hpp
#ifndef SENIORDEVELOPER_HPP
#define SENIORDEVELOPER_HPP

#include "Developer.hpp"

class SeniorDeveloper : public Developer {
public:
    SeniorDeveloper(const std::string& name, const std::string& aliasName);
    void solve_problem() const override;
};

#endif