#include<iostream>

int main () {
    int a, b;
    std::cout << "A = ";
    std::cin >> a;
    std::cout << "B = ";
    std::cin >> b;

    if (a == b) {
        std::cout << "A y B son iguales.\n";
    } else if (a < b) {
        std::cout << "A es menor que B.\n";
    } else {
        std::cout << "A es mayor que B.\n";
    }
}
