#include <iostream>

class Foo {
public:
    Foo() {
        std::cout << "Foo()\n";
    }

    explicit Foo(int v) {
        std::cout << "Foo(int) -> " << v << "\n";
    }

    Foo(const Foo & obj) {
        std::cout << "Foo(const Foo &)\n";
    }

    Foo(Foo && obj) {
        std::cout << "Foo(Foo &&)\n";
    }

    virtual ~Foo() {
        std::cout << "~Foo()\n";
    }

    Foo & operator =(const Foo & obj) {
        std::cout << "operator =(const Foo &)\n";
        return *this;
    }

    Foo & operator =(Foo && obj) {
        std::cout << "operator =(Foo &&)\n";
        return *this;
    }
};

int main () {
    Foo a, b(42), c(a), d(std::move(c));
    b = d;
    a = std::move(b);
}
