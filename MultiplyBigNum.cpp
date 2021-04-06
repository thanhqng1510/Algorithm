#include <iostream>
#include <cmath>

long long multiply(const long long& a, const long long& b, const long long& mod) {
    if (b == 0)
        return 0;
    
    return ((2 * multiply(a, b / 2, mod)) % mod + a * (b % 2 == 1)) % mod;
}

int main() {
    long long a = 3 * pow(10, 18), b = 3 * pow(10, 18), mod = pow(10, 18);
    std::cout << multiply(a, b, mod) << std::endl;
}
