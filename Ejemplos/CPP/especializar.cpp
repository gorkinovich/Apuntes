#include <iostream>

template<typename T>
void mostrar_valor (T valor) {
    std::cout << valor;
}

template<>
void mostrar_valor<bool> (bool valor) {
    std::cout << (valor ? "true" : "false");
}

template<>
void mostrar_valor<const char *> (const char * valor) {
    std::cout << '"' << valor << '"';
}

template<typename T1, typename T2>
struct Tupla {
    T1 primero;
    T2 segundo;

    void mostrar () {
        std::cout << "{ ";
        mostrar_valor(primero);
        std::cout << ", ";
        mostrar_valor(segundo);
        std::cout << " }\n";
    }
};

int main () {
    auto v1 = Tupla{1, true};
    auto v2 = Tupla{3.14, "PI"};
    v1.mostrar(); // { 1, true }
    v2.mostrar(); // { 3.14, "PI" }
}
