#include <iostream>

class A {
public:
    virtual void foo () = 0;
    virtual void bar () {
        std::cout << "A::bar()\n";
    }
};

class B : public A {
public:
    void foo () final {
        std::cout << "B::foo()\n";
    }
    void bar () override = 0;
};

class C : public B {
public:
    void bar () override {
        std::cout << "C::bar()\n";
    }
};

class D : public A {
public:
    void foo () override {
        std::cout << "D::foo()\n";
    }
};

int main () {
    A * c = new C();
    c->foo(); // B::foo()
    c->bar(); // C::bar()

    A * d = new D();
    d->foo(); // D::foo()
    d->bar(); // A::bar()

    delete c;
    delete d;
}
