#include<iostream>

void main () {
	const auto a = 123; // const int a
	std::cout << a << "\n"; // 123

	const auto b = "hola"; // const char * const b
	std::cout << b << "\n"; // hola
	// Ilegal: b[0] = 'H';
	// Ilegal: b = "Hola";

	const char * c = "hola";
	std::cout << c << "\n"; // hola
	// Ilegal: c[0] = 'H';
	c = "Hola";
	std::cout << c << "\n"; // Hola

	char cadena[] = "hola";
	char * const d = cadena;
	std::cout << d << "\n"; // hola
	d[0] = 'H';
	// Ilegal: d = "Hola";
	std::cout << d << "\n"; // Hola
}
