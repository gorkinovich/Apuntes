#include <string>
#include <iostream>

struct Foo {
    int X, Y;
};

std::ostream & operator <<(std::ostream & out, const Foo & obj) {
    out << "(" << obj.X << "," << obj.Y << ")";
    return out;
}

Foo operator ""_f(const char * v, size_t) {
    std::string texto{v};
    auto coma = texto.find(',');
    return Foo{
        .X = std::stoi(texto.substr(0, coma)),
        .Y = std::stoi(texto.substr(coma + 1))
    };
}

int main () {
    std::cout << "2,3"_f << "\n";
}
