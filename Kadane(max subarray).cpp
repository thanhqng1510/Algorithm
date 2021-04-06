#include <iostream>
using namespace std;

int Kadane(int a[], int n) {
    int max_cur = a[0], max_global = a[0];
    for (int i = 1; i < n; ++i) {
        (max_cur > 0) ? (max_cur += a[i]) : (max_cur = a[i]);
        if (max_cur > max_global)
            max_global = max_cur;
    }
    return max_global;
}

int Stu(int a[], int n) {
    int max_cur = 0, max_global = a[0];
    for (int i = 0; i < n; ++i) {
        max_cur += a[i];
        if (max_cur > max_global)
            max_global = max_cur;
        if (max_cur < 0)
            max_cur = 0;
    }
    return max_global;
}

int main() {
    int a[] = {1, -1, 2, -3, 0, 1}, n = 6;
    cout << Kadane(a, n) << endl;
    cout << Stu(a, n) << endl;
}
