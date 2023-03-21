#include<iostream>

int main (int argc, char ** argv) {
	std::cout << "Argumentos: " << argc << "\n";
	for (int i = 0; i < argc; i++) {
		std::cout << i << ": " << argv[i] << "\n";
	}
    return 0;
}
