#include <string>
#include <iostream>

int main () {
    std::string nombre;
    std::cout << "Nombre: ";
    if (std::cin >> nombre; !nombre.empty()) {
        std::cout << "Hola, " << nombre << ".\n";
    }
}
