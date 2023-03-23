#include <cstdarg>
#include <iostream>

int sum (int n, ...) {
	int r = 0;
	std::va_list args;
	va_start(args, n);
	for (int i = 0; i < n; i++) {
		r += va_arg(args, int);
	}
	va_end(args);
	return r;
}

void main () {
	std::cout << sum(4, 1, 2, 3, 4) << "\n"; // 10
}
