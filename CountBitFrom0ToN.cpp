#include <iostream>
#include <vector>


std::vector<int> CountBit(int n) {
    std::vector<int> res(n + 1, 0);
    int prevThreshHold = 1, threshHold = 1;
    
    for (int i = 1; i <= n; ++i) {
        if (i == threshHold) {
            prevThreshHold = threshHold;
            threshHold *= 2;
            res[i] = 1;
        }
        else
            res[i] = res[prevThreshHold] + res[i - prevThreshHold];
    }
    
    return res;
}


int main() {
    int n = 16;
    auto v = CountBit(n);
    for (int i : v)
        std::cout << i << " ";
    std::cout << "\n";
}
