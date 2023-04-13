#include <cstdint>
#include <iostream>

constexpr uint8_t MAX_VALUE = 46;

template<uint8_t n>
class MetaFibonacci {
private:
    template<uint8_t i, uint64_t v0, uint64_t v1>
    class fibonacci {
    public:
        enum {
            Result = fibonacci<i - 1, v1, v0 + v1>::Result
        };
    };
    template<uint64_t v0, uint64_t v1>
    class fibonacci<0, v0, v1> {
    public:
        enum {
            Result = v0
        };
    };
public:
    enum {
        Result = fibonacci<n, 0, 1>::Result
    };
};

template<unsigned char n>
inline void print_numbers() {
    print_numbers<n - 1>();
    std::cout << ", ";
    std::cout << MetaFibonacci<n>::Result;
}

template<>
inline void print_numbers<0>() {
    std::cout << MetaFibonacci<0>::Result;
}

int main () {
    std::cout << "Fibonacci: ";
    print_numbers<MAX_VALUE>();
    std::cout << "\n";
}
