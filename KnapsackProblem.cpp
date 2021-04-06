#include <iostream>
using namespace std;

int Max(int a, int b) {
    return (a > b) ? a : b;
}

int KnapSack(int w, int* weight, int* value, int n) {
    if (n == 0 || w == 0)
        return 0;
    
    if (weight[n - 1] > w)
        return KnapSack(w, weight, value, n - 1);
    else
        return Max(KnapSack(w, weight, value, n - 1),  value[n - 1] + KnapSack(w - weight[n - 1], weight, value, n - 1));
}

int KnapSack_BottomUp(int w, int* weight, int* value, int n) {
    int res[n + 1][w + 1];
    for (int tmp_n = 0; tmp_n <= n; ++tmp_n)
        for (int tmp_w = 0; tmp_w <= w ; ++tmp_w) {
            if (tmp_n == 0 || tmp_w == 0)
                res[tmp_n][tmp_w] = 0;
            else if (weight[tmp_n - 1] > tmp_w)
                res[tmp_n][tmp_w] = res[tmp_n - 1][tmp_w];
            else
                res[tmp_n][tmp_w] = Max(res[tmp_n - 1][tmp_w], value[tmp_n - 1] + res[tmp_n - 1][tmp_w - weight[tmp_n - 1]]);
        }
    return res[n][w];
}

int main() {
    int value[] = {100, 60, 120}, weight[] = {20, 10, 30}, n = 3, w = 50;
    cout << KnapSack(w, weight, value, n) << endl;
    cout << KnapSack_BottomUp(w, weight, value, n) << endl;
}
