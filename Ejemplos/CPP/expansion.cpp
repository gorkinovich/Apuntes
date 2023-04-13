#include <iostream>

template<typename T, typename... TS>
void mostrar (T value, TS... args) {
    std::cout << value;
    if constexpr (sizeof...(TS) > 0) {
        mostrar(args...);
    }
}

int main () {
    mostrar(1, ", ", 2, ", ", 3, ", ", 4, "\n");
}
