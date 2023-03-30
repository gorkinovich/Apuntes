#include<iostream>

int main () {
    int a = 1, b = 2;
    auto c = 3.14;
    std::cout << a << ", " << b << ", " << c << "\n"; // 1, 2, 3.14
    b = 4;
    std::cout << a << ", " << b << ", " << c << "\n"; // 1, 4, 3.14
}
