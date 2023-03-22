#include <string>
#include <iostream>

void main () {
	const int SIZE = 4;
	int nums[SIZE] = { 1, 2, 3, 4 };
	std::string respuesta;
	do {
		int i = 0;
		std::cout << "While: ";
		while (i < SIZE) {
			std::cout << nums[i] << " ";
			++i;
		}
		std::cout << "\n";

		std::cout << "For: ";
		for (int j = 0; j < SIZE; j++) {
			std::cout << nums[j] << " ";
		}
		std::cout << "\n";

		std::cout << "For each: ";
		for (auto n : nums) {
			std::cout << n << " ";
		}
		std::cout << "\n";

		std::cout << "¿Salir? (S/N) ";
		std::cin >> respuesta;
	} while (respuesta != "s" && respuesta != "S");
}
