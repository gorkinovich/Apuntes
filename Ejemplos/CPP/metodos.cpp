#include<iostream>

class Foo {
public:
    const int a = 1;
    mutable int b = 2;
    int c = 3;

    int foo (int) const;

    void bar () {
        std::cout << a << ", " << b << ", "
            << ++c << "; " << foo(c) << "\n";
    }
};

int Foo::foo(int a) const {
    a *= this->a + (b++);
    return a + a;
}

int main () {
    Foo obj;
    obj.bar(); // 1, 2, 4; 24
    obj.bar(); // 1, 3, 5; 40
}
