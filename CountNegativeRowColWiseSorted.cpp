#include <iostream>

int& Negative(const int a[][4], const int& r, const int& c) {
    static int count = 0;
    int i_r = 0, i_c = c - 1;
    while (i_r < r && i_c >= 0) {
        if (a[i_r][i_c] < 0) {
            count += i_c + 1;
            ++i_r;
        }
        else
            --i_c;
    }
    return count;
}

int main() {
    int a[3][4] = {
        {-10, -9, -4, -2},
        {-5, -4,  -2, 0},
        { -4, -3,  -2, 1}
    }, r = 3, c = 4;
    int& count = Negative(a, r, c);
    std::cout << count << std::endl;
}
