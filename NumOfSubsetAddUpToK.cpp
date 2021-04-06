#include <iostream>
using namespace std;

int NumSubSet(const int* const a, const int& n, const int& k) {
    if (n == 0)
        return (k == 0) ? 1 : 0;
    
    // k is not 16 anymore, k is now the remain of k - a[num]
    return NumSubSet(a, n - 1, k - a[n - 1]) + NumSubSet(a, n - 1, k);
}

int NumSubSet_Memoi(const int* const a, const int& n, const int& k, int** mem) {
    if (mem[n][k] == -1) {
        if (n == 0 || k == 0)
            mem[n][k] = (k == 0) ? 1 : 0;
        else
            mem[n][k] = NumSubSet_Memoi(a, n - 1, k - a[n - 1], mem) + NumSubSet_Memoi(a, n - 1, k, mem);
    }
    return mem[n][k];
}

int main() {
    int a[]{ 2, 4, 6, 10, 16 }, n(sizeof(a) / sizeof(a[0])), k = 16;
    int** mem = new int* [n + 1];
    for (int i = 0; i < n + 1; ++i)
        mem[i] = new int [k + 1];
    for (int i = 0; i < n + 1; ++i)
        for (int j = 0; j < k + 1; ++j)
            mem[i][j] = -1;
    
    cout << NumSubSet(a, n, k) << endl;
    
    cout << NumSubSet_Memoi(a, n, k, mem) << endl;
    
    for (int i = 0; i < n; ++i)
        delete [] mem[i];;
    delete [] mem;
}
