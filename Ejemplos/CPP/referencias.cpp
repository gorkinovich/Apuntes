#include<iostream>

void main () {
	int a { 8 };
	int b[] { 5, 4, 3, 2, 1 };
	int c[][3] { { 1, 2, 3 }, { 4, 5, 6 } };

	auto & ra = a; // int & ra = a;
	auto & rb = b; // int (& rb)[5] = b;
	auto & rc = c; // int (& rc)[2][3] = c;

	std::cout << ra << "\n"; // 8
	std::cout << rb[2] << "\n"; // 3
	std::cout << rc[0][0] << "\n"; // 1
	std::cout << rc[1][1] << "\n"; // 5
}
