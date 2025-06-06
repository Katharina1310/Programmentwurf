#ifndef DEVELOPER_HPP
#define DEVELOPER_HPP

#include <string>
#include <stdexcept>

// Abstract base class representing a generic developer
class Developer
{
protected:
    // Member variables to store developer's name, alias, and logo (ASCII art)
    std::string name;
    std::string alias_name;
    std::string logo;

public:
    // Constructor initializing name and alias name
    Developer(const std::string& name, const std::string& alias_name);

    // Static method simulating the developer drinking coffee
    static void drink_coffee();

    // Method to load ASCII logo from a file and store it in the logo string
    void load_logo_from_file(const std::string& file_name);

    // Getter for the real name
    std::string get_name() const;

    // Getter for the alias name
    std::string get_alias_name() const;

    // Getter for the loaded logo
    std::string get_logo() const;

    // Used to simulate solving a problem
    virtual void solve_problem() const = 0;

    // Virtual destructor (commented out here, but recommended in real use)
    // virtual ~Developer() = default;
};

// Overloaded stream insertion operator to output developer information
std::ostream& operator<<(std::ostream& os, const Developer& dev);

#endif
