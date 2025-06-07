/**
 * @file JuniorDeveloper.hpp
 * @brief Declaration of the JuniorDeveloper class, derived from Developer.
 */

#ifndef JUNIOR_DEVELOPER_HPP
#define JUNIOR_DEVELOPER_HPP

#include "developer.hpp"

/**
 * @class JuniorDeveloper
 * @brief Represents a junior developer, subclass of Developer.
 */
class JuniorDeveloper : public Developer {
public:
    /**
     * @brief Constructor initializing the JuniorDeveloper with a name and alias.
     * @param name The real name of the junior developer.
     * @param alias_name The alias or nickname of the junior developer.
     */
    JuniorDeveloper(const std::string& name, const std::string& alias_name);

    /**
     * @brief Implementation of problem solving specific to a junior developer.
     */
    void solve_problem() const override;
};

#endif
