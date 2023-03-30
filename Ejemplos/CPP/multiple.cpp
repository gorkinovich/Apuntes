#include<iostream>

class A {
public:
    void hola () {
        std::cout << "Hola\n";
    }
};

class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

int main () {
    D objeto;
    objeto.hola();
}
