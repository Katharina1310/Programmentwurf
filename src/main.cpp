// Datei: src/main.cpp
#include <iostream>
#include <vector>
#include <memory>
#include "JuniorDeveloper.hpp"
#include "SeniorDeveloper.hpp"

int main() {
    std::vector<std::shared_ptr<Developer>> devs;

    auto senior = std::make_shared<SeniorDeveloper>("Abu", "Aladins Affe");
    auto junior = std::make_shared<JuniorDeveloper>("Anikan Skywalker", "Darth Vader");

    try {
        senior->load_logo_from_file("Abu.txt");
        junior->load_logo_from_file("Darth_Vader.txt");
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    devs.push_back(senior);
    devs.push_back(junior);

    for (const auto& dev : devs) {
        dev->solve_problem();
    }
    std::cout << "\nPress Enter to exit...";
    std::cin.get();

    return 0;
}
