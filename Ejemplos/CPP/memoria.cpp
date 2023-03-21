#include<iostream>

void main () {
	int * a = new int { 8 };
	std::cout << *a << "\n"; // 8
	delete a;

	int * b = new int[5] { 5, 4, 3, 2, 1 };
	std::cout << b[2] << "\n"; // 3
	delete[] b;

	int ** c = new int*[2] {
		new int[3] { 1, 2, 3 },
		new int[4] { 4, 5, 6, 7 }
	};
	std::cout << c[0][2] << "\n"; // 3
	std::cout << c[1][3] << "\n"; // 7
	delete[] c[0];
	delete[] c[1];
	delete[] c;
}
