#include <iostream>

template<typename... TS>
auto sumar (TS... args) {
    return (0 + ... + args);
}

int main () {
    std::cout << sumar(1, 2, 3, 4) << "\n";
}
