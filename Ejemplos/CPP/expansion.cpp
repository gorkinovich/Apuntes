#include <iostream>

// Versión estándar de mostrar:
void mostrar () {}

template<typename T, typename... TS>
void mostrar (T value, TS... args) {
    std::cout << value;
    mostrar(args...);
}

// Versión alternativa de mostrar:
template<typename T, typename... TS>
void mostrarsi (T value, TS... args) {
    std::cout << value;
    if constexpr (sizeof...(TS) > 0) {
        mostrar(args...);
    }
}

int main () {
    mostrar(1, ", ", 2, ", ", 3, ", ", 4, "\n");
    mostrarsi(1.2, ", ", 3.4, "\n");
}
