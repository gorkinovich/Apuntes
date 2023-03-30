#include<iostream>

int main () {
    int x = 1;
    std::cout << ++x << "\n"; // 2
    std::cout << x++ << "\n"; // 2
    std::cout << x   << "\n"; // 3
}
