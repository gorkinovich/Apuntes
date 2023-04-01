#include <iostream>

union Foo {
    char a;
    short b;
    int c;
};

int main () {
    Foo v;
    v.c = 0x12345678;
    std::cout << std::hex << v.c << "\n"; // 12345678
    std::cout << std::hex << v.b << "\n"; // 5678
    std::cout << std::hex << (int)v.a << "\n"; // 78
}
