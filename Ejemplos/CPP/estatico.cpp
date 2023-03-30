#include<iostream>

class Foo {
public:
    static int a;
    static int foo (int);
};

int Foo::a = 0;

int Foo::foo(int b) {
    a += b;
    return a;
}

int main () {
    Foo::a = 10;
    std::cout << Foo::a      << "\n"; // 10
    std::cout << Foo::foo(1) << "\n"; // 11
}