#include <iostream>

void main () {
	int xs[] = {
		1, 2, 3, 4, 5, 6, 7, 0, 8, 9
	};

	for (auto x : xs) {
		if (x == 0) break;
		if (x % 2 == 0) continue;
		std::cout << x << " ";
	}
	std::cout << "\n";
	// 1 3 5 7
}
