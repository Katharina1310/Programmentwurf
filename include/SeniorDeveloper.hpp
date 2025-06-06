/**
 * @file SeniorDeveloper.hpp
 * @brief Declaration of the SeniorDeveloper class, derived from Developer.
 */

#ifndef SENIORDEVELOPER_HPP
#define SENIORDEVELOPER_HPP

#include "Developer.hpp"

/**
 * @class SeniorDeveloper
 * @brief Represents a senior developer, subclass of Developer.
 */
class SeniorDeveloper : public Developer {
public:
    /**
     * @brief Constructor initializing the SeniorDeveloper with a name and alias.
     * @param name The real name of the senior developer.
     * @param aliasName The alias or nickname of the senior developer.
     */
    SeniorDeveloper(const std::string& name, const std::string& aliasName);

    /**
     * @brief Implementation of problem solving specific to a senior developer.
     */
    void solve_problem() const override;
};

#endif
