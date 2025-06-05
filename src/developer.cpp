#include "developer.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

// Constructor initializes name & alias_name and sets logo to an empty string
Developer::Developer(const std::string& name, const std::string& alias_name)
    : name(name), alias_name(alias_name), logo("") {}

// Static method:
void Developer::drink_coffee() {
    std::cout << "Ahhhh, I needed that coffee!!!" << std::endl;
}

// Loads the logo from a file specified by filename and stores it in the member variable 'logo'
void Developer::load_logo_from_file(const std::string& filename) {
    // Check if the filename is empty and throw an error if so
    if (filename.empty()) {
        throw std::invalid_argument("Filename is empty.");
    }

    // Open the logo file with the given path and filename
    std::ifstream file(LOGO_PATH + filename);
    
    // Throw an error if the file could not be opened
    if (!file.is_open()) {
        throw std::runtime_error("Logo file could not be opened: " + filename);
    }

    // Read the file line by line and accumulate its contents into a string stream
    std::ostringstream content;
    std::string line;
    while (std::getline(file, line)) {
        content << line << '\n';
    }

    // Store the read content into the member variable 'logo'
    logo = content.str();
}

// Getter method to return the developer's name
std::string Developer::get_name() const {
    return name;
}

// Getter method to return the developer's alias name
std::string Developer::get_alias_name() const {
    return alias_name;
}

// Getter method to return the stored logo as a string
std::string Developer::get_logo() const {
    return logo;
}

// stream-operator for Developer
std::ostream& operator<<(std::ostream& os, const Developer& dev) {
    os << "Name: " << dev.get_name() << "\n"
       << "Alias: " << dev.get_alias_name() << "\n";

    if (!dev.get_logo().empty()) {
        os << "\nLogo:\n" << dev.get_logo();
    }

    return os;
}

