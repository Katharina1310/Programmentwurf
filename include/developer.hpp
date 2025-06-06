#ifndef DEVELOPER_HPP
#define DEVELOPER_HPP

#include <string>
#include <stdexcept>

/**
 * @brief Abstract base class representing a generic developer.
 */
class Developer
{
protected:
    /** Developer's real name */
    std::string name;

    /** Developer's alias or nickname */
    std::string alias_name;

    /** Developer's ASCII art logo */
    std::string logo;

public:
    /**
     * @brief Constructor initializing the developer's name and alias.
     * @param name Real name of the developer.
     * @param alias_name Alias or nickname of the developer.
     */
    Developer(const std::string& name, const std::string& alias_name);

    /**
     * @brief Static method simulating the developer drinking coffee.
     */
    static void drink_coffee();

    /**
     * @brief Loads the ASCII logo from a file into the member variable.
     * @param file_name The path to the logo file.
     * @throws std::runtime_error if file cannot be opened.
     */
    void load_logo_from_file(const std::string& file_name);

    /**
     * @brief Getter for the developer's real name.
     * @return The name of the developer.
     */
    std::string get_name() const;

    /**
     * @brief Getter for the developer's alias name.
     * @return The alias of the developer.
     */
    std::string get_alias_name() const;

    /**
     * @brief Getter for the loaded ASCII logo.
     * @return The logo string.
     */
    std::string get_logo() const;

    /**
     * @brief Pure virtual method to simulate solving a problem.
     * Must be implemented by derived classes.
     */
    virtual void solve_problem() const = 0;

    /**
     * @brief Virtual destructor (recommended).
     */
    // virtual ~Developer() = default;
};

/**
 * @brief Overloads the stream insertion operator to output developer information.
 * @param os The output stream.
 * @param dev The Developer object to output.
 * @return The output stream.
 */
std::ostream& operator<<(std::ostream& os, const Developer& dev);

#endif
