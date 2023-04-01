#include <iostream>

enum Bar { A = 10, B, C };
enum class Foo : int { A, B, C };

int main () {
    Bar b = A;
    std::cout << b << "\n";
    {
        std::cout << A << "\n";
        std::cout << B << "\n";
        std::cout << C << "\n";
    }
    Foo f = Foo::A;
    std::cout << (int) f << "\n";
    {
        using enum Foo;
        std::cout << (int) A << "\n";
        std::cout << (int) B << "\n";
        std::cout << (int) C << "\n";
    }
}
