#include "developer.hpp" // dieser inkludiert "developer.hpp"
#include <iostream>

int main() {
    Developer dev("Lena", "CodeQueen");

    dev.drink_coffee();

    try {
        dev.load_logo_from_file("logo.txt");
        std::cout << "Logo:\n" << dev.get_logo() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Fehler beim Laden des Logos: " << e.what() << std::endl;
    }

   

    return 0;
}

