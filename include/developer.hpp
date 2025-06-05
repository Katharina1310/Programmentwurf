#ifndef DEVELOPER_HPP
#define DEVELOPER_HPP

#include <string>
#include <stdexcept>
class Developer
{
    //member variables:
    protected:
    std::string name;
    std::string alias_name;
    std::string logo;

    public:
    //constructor for name and alias_name:
    Developer(const std::string& name, const std::string& alias_name);

    //static method drink_coffee:
    static void drink_coffee();

    //non-virtual method load_logo_from_file:
    void load_logo_from_file(const std::string& file_name);

    //getter-methods:
    std::string get_name() const;
    std::string get_alias_name() const;
    std::string get_logo() const;
    
    //virtual method solve_problem:
    //virtual void solve_problem() const = 0;
    //virtual ~Developer() = default;  

};

//stream-operator for Developer:
std::ostream& operator<<(std::ostream& os, const Developer& dev);

#endif