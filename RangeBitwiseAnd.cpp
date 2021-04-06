/*
 Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
 */


// ------------------------------------


#include <iostream>


int RangeBitwiseAnd(int m, int n) {
    int res = 0;
    for (int i = 30; i >= 0; --i) {
        int m_i = m & (1 << i), n_i = n & (1 << i);
        if (m_i != n_i)
            break;
        else
            res |= m_i;
    }
    return res;
}


int main(int argc, const char * argv[]) {
    std::cout << RangeBitwiseAnd(5, 7) << "\n";
}
