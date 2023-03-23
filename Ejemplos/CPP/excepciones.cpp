#include <iostream>

void main () {
	try {
		throw 42;
		std::cout << "Todo fue bien\n";
	} catch (...) {
		std::cout << "Error inesperado\n";
	}
}
