#include<iostream>

int main () {
    int a = 24;
    std::cout << a << "\n"; // 24

    int * b = &a;
    *b = 42;
    std::cout << a << "\n"; // 42
}
