#include <iostream>

class Bar {
private:
    int dato = 0;
public:
    void mostrar() {
        std::cout << dato << "\n";
    }

    friend class Foo;
};

class Foo {
public:
    void cambiar (Bar & obj, int valor) {
        obj.dato = valor;
    }
};

int main () {
    Foo a;
    Bar b;
    b.mostrar(); // 0
    a.cambiar(b, 1);
    b.mostrar(); // 1
}
