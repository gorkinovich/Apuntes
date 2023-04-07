#include <iostream>

struct Foo {
    int X, Y;
};

std::ostream & operator <<(std::ostream & out, const Foo & obj) {
    out << "(" << obj.X << "," << obj.Y << ")";
    return out;
}

inline Foo operator +(const Foo & left, const Foo & right) {
    return Foo{
        .X = left.X + right.X,
        .Y = left.Y + right.Y
    };
}

int main () {
    Foo v{2, 3}, w{4, 5};
    std::cout << v << " + " << w << " = "
              << (v + w) << "\n";
}
