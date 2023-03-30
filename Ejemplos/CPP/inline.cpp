#include<iostream>

inline void foo (int a, int b) {
    std::cout << a << " + " << b << " = " << a + b << "\n";
}

int main () {
    foo(2 , 3);
}
