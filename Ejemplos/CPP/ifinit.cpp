#include <string>
#include <iostream>

void main () {
	std::string nombre;
	std::cout << "Nombre: ";
	if (std::cin >> nombre; !nombre.empty()) {
		std::cout << "Hola, " << nombre << ".\n";
	}
}
