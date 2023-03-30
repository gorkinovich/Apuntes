#include<iostream>

int main () {
    int a[2];
    a[0] = 1;
    a[1] = 2;
    std::cout << a[0] << ", " << a[1] << "\n"; // 1, 2

    char b[] = "Hola"; // char b[5]
    std::cout << b << "\n"; // Hola

    int c[][2] = { {1, 2}, {3, 4} }; // int c[2][2]
    std::cout << c[0][0] << ", " << c[0][1] << "\n"; // 1, 2
    std::cout << c[1][0] << ", " << c[1][1] << "\n"; // 3, 4

    char d[][20] = { "inicio", "final" }; // char d[2][20]
    std::cout << d[0] << "\n"; // inicio
    std::cout << d[1] << "\n"; // final
}
