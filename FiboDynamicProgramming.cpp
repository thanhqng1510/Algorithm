#include <iostream>
using namespace std;

int64_t Fibo(int n) {
    if (n <= 2)
        return 1;
    return Fibo(n - 1) + Fibo(n - 2);
}

int64_t Fibo_Memoization(int n, int64_t* memo) {
    if (memo[n - 1] == -1) {
        if (n <= 2)
            memo[n - 1] = 1;
        else
            memo[n - 1] = Fibo_Memoization(n - 1, memo) + Fibo_Memoization(n - 2, memo);
    }
    return memo[n - 1];
}

int64_t Fibo_BottomUp(int n, int64_t* res) {
    for (int i = 2; i < n; ++i)
        res[i] = res[i - 1] + res[i - 2];
    return res[n - 1];
}

int main() {
    int n;
    cout << "Input n: ";
    cin >> n;
    int64_t* memo = new int64_t [n];
    for (int i = 0; i < n; ++i)
        memo[i] = -1;
    cout << Fibo_Memoization(n, memo) << endl;
    int64_t* res = new int64_t [n];
    res[0] = 1;
    res[1] = 1;
    cout << Fibo_BottomUp(n, res);
    cout << Fibo(n) << endl;
    delete [] memo;
    delete [] res;
}
