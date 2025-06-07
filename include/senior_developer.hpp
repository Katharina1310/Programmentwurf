/**
 * @file SeniorDeveloper.hpp
 * @brief Declaration of the SeniorDeveloper class, derived from Developer.
 */

#ifndef SENIOR_DEVELOPER_HPP
#define SENIOR_DEVELOPER_HPP

#include "developer.hpp"

/**
 * @class SeniorDeveloper
 * @brief Represents a senior developer, subclass of Developer.
 */
class SeniorDeveloper : public Developer {
public:
    /**
     * @brief Constructor initializing the SeniorDeveloper with a name and alias.
     * @param name The real name of the senior developer.
     * @param alias_name The alias or nickname of the senior developer.
     */
    SeniorDeveloper(const std::string& name, const std::string& alias_name);

    /**
     * @brief Implementation of problem solving specific to a senior developer.
     */
    void solve_problem() const override;
};

#endif
