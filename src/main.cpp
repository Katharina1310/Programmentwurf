// Datei: src/main.cpp
#include <iostream>
#include <vector>
#include <memory>
#include "JuniorDeveloper.hpp"
#include "SeniorDeveloper.hpp"

int main() {
    std::vector<std::shared_ptr<Developer>> devs;

    auto senior = std::make_shared<SeniorDeveloper>("Diana Prince", "Wonder Woman");
    auto junior = std::make_shared<JuniorDeveloper>("Peter Parker", "Spiderman");

    try {
        senior->load_logo_from_file("wonder_woman.txt");
        junior->load_logo_from_file("spiderman.txt");
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    devs.push_back(senior);
    devs.push_back(junior);

    for (const auto& dev : devs) {
        dev->solve_problem();
    }
    std::cout << "\nDruecken Sie die Eingabetaste, um das Programm zu beenden...";
    std::cin.get();
    return 0;
}
