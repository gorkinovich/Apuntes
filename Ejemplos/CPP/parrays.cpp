#include<iostream>

int main () {
    char c[] = "cadena";
    char * d = c;

    std::cout << d[2] << "\n"; // d
    std::cout << *(d+2) << "\n"; // d
}
