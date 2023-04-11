#include <iostream>

template<typename T1, typename T2>
struct Tupla {
    T1 primero;
    T2 segundo;
};

template<typename T1, typename T2>
void mostrar (const Tupla<T1, T2> & valor) {
    std::cout << "{ " << valor.primero
              << ", " << valor.segundo
              << " }\n";
}

int main () {
    auto v1 = Tupla{1, true};
    auto v2 = Tupla{3.14, "PI"};
    mostrar(v1); // { 1, 1 }
    mostrar(v2); // { 3.14, PI }
}
