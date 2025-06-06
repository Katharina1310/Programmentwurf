/**
 * @file main.cpp
 * @brief Main program to create and manage Developer objects.
 */

#include <iostream>
#include <vector>
#include <memory>
#include "JuniorDeveloper.hpp"
#include "SeniorDeveloper.hpp"

/**
 * @brief Main function to run the developer simulation.
 * 
 * Creates SeniorDeveloper and JuniorDeveloper objects, loads their logos,
 * and calls their problem-solving methods.
 * 
 * @return int Exit status code.
 */
int main() {
    /** 
     * @brief Vector holding shared pointers to Developer instances
     */
    std::vector<std::shared_ptr<Developer>> devs;

    /**
     * @brief Create a SeniorDeveloper instance dynamically
     */
    auto senior = std::make_shared<SeniorDeveloper>("Abu", "Aladdin's monkey");

    /**
     * @brief Create a JuniorDeveloper instance dynamically
     */
    auto junior = std::make_shared<JuniorDeveloper>("Anakin Skywalker", "Darth Vader");

    try {
        /**
         * @brief Load logo for the SeniorDeveloper from file
         */
        senior->load_logo_from_file("Abu.txt");

        /**
         * @brief Load logo for the JuniorDeveloper from file
         */
        junior->load_logo_from_file("Darth_Vader.txt");
    } catch (const std::runtime_error& e) {
        /**
         * @brief Output error message if loading logo fails
         */
        std::cerr << e.what() << std::endl;
    }

    /** @brief Add developers to the vector */
    devs.push_back(senior);
    devs.push_back(junior);

    /** 
     * @brief Loop through developers and invoke their solve_problem method
     * 
     * Prints two empty lines after each developer except the last
     */
    for (size_t i = 0; i < devs.size(); ++i) {
        devs[i]->solve_problem();

        if (i < devs.size() - 1) {
            std::cout << "\n\n";
        }
    }

    /** @brief Wait for user input before exiting */
    std::cout << "\nPress Enter to exit...";
    std::cin.get();

    return 0;
}
