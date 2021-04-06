#include <iostream>
using namespace std;

int Min(const int* const a , const int& k) {
    int min = a[0];
    for (int i = 0; i < k; ++i)
        if (a[i] < min)
            min = a[i];
    return min;
}

int UglyNum_BottomUp(const int& n, const int* const primes, const int& k) {
    int ugly_nums[n];
    ugly_nums[0] = 1;
    
    int indexes[k];
    memset(indexes, 0, sizeof(indexes));
    
    int next_multiples[k];
    for (int i = 0; i < k; ++i)
        next_multiples[i] = ugly_nums[indexes[i]] * primes[i];
    
    for (int i = 1; i < n; ++i) {
        ugly_nums[i] = Min(next_multiples, k);
        for (int j = 0; j < k; ++j)
            if (ugly_nums[i] == next_multiples[j]) {
                ++indexes[j];
                next_multiples[j] = ugly_nums[indexes[j]] * primes[j];
            }
    }
    return ugly_nums[n - 1];
}

int main() {
    int primes[] = { 3, 5, 7 }, k = 3;
    cout << UglyNum_BottomUp(10, primes, k) << endl;
}
