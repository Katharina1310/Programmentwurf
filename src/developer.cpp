/**
 * @file developer.cpp
 * @brief Implementation of the Developer class.
 * 
 * Contains the implementation of methods for initializing a developer,
 * loading a logo from file, and accessing developer details.
 */

#include "developer.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

/**
 * @brief Constructor initializes name and alias_name and sets logo to an empty string.
 * 
 * @param name The real name of the developer.
 * @param alias_name The alias or nickname of the developer.
 */
Developer::Developer(const std::string& name, const std::string& alias_name)
    : name(name), alias_name(alias_name), logo("") {}

/**
 * @brief Static method that simulates the developer drinking coffee.
 */
void Developer::drink_coffee() {
    std::cout << "Ahhhh, I needed that coffee!!!" << std::endl;
}

/**
 * @brief Loads the logo from a file specified by filename.
 * 
 * The logo content is stored in the member variable 'logo'.
 * 
 * @param filename Name of the file to load the logo from.
 * 
 * @throws std::invalid_argument if filename is empty.
 * @throws std::runtime_error if the file cannot be opened.
 */
void Developer::load_logo_from_file(const std::string& filename) {
    // Check for empty filename
    if (filename.empty()) {
        throw std::invalid_argument("Filename is empty.");
    }

    // Construct full path to logo file
    std::string fullPath = std::string(LOGO_PATH) + filename;

    // Open the file
    std::ifstream file(fullPath);
    if (!file.is_open()) {
        throw std::runtime_error("Logo file could not be opened: " + fullPath);
    }

    // Read the file content line by line
    std::ostringstream content;
    std::string line;
    while (std::getline(file, line)) {
        content << line << '\n';
    }

    // Store the content in the logo attribute
    logo = content.str();
}

/**
 * @brief Returns the developer's real name.
 * 
 * @return std::string The name of the developer.
 */
std::string Developer::get_name() const {
    return name;
}

/**
 * @brief Returns the developer's alias name.
 * 
 * @return std::string The alias name of the developer.
 */
std::string Developer::get_alias_name() const {
    return alias_name;
}

/**
 * @brief Returns the stored logo as a string.
 * 
 * @return std::string The logo content.
 */
std::string Developer::get_logo() const {
    return logo;
}

/**
 * @brief Stream operator to output developer details.
 * 
 * Outputs name, alias, and if available, the logo.
 * 
 * @param os Output stream.
 * @param dev Developer object to output.
 * @return std::ostream& The output stream.
 */
std::ostream& operator<<(std::ostream& os, const Developer& dev) {
    os << "Name: " << dev.get_name() << "\n"
       << "Alias: " << dev.get_alias_name() << "\n";

    if (!dev.get_logo().empty()) {
        os << "\nLogo:\n" << dev.get_logo();
    }

    return os;
}
