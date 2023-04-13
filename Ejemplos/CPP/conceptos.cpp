#include <vector>
#include <iostream>

template<typename P, typename T>
concept Predicado = requires (P p, T x) {
    {p(x)} -> std::same_as<bool>;
};

template<typename T, typename P>
void mostrar (const T & datos, P predicado)
	requires Predicado<P, typename T::value_type> {
	for (auto item : datos) {
		if (predicado(item)) {
			std::cout << item << " ";
		}
	}
	std::cout << "\n";
}

int main () {
	std::vector datos = {1, 2, 3, 4, 5, 6, 7, 8};
	mostrar(datos, [](int x) { return x % 2 == 0; });
}
