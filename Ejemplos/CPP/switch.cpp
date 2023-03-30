#include<iostream>

int main () {
    int a;
    std::cout << "> ";
    std::cin >> a;

    switch (a) {
    case 5:
        std::cout << "Cinco.\n";
    case 4:
        std::cout << "Cuatro.\n";
    case 3:
        std::cout << "Tres.\n";
    case 2:
        std::cout << "Dos.\n";
    case 1:
        std::cout << "Uno.\n";
    case 0:
        std::cout << "Cero.\n";
        break;
    default:
        std::cout << "Indefinido.\n";
    }
}
