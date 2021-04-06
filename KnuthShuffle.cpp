#include <iostream>
using namespace std;

void Random(int* a, int n) {
    for (int i = n - 1; i >= 0; --i) {
        int pick = rand() % (i + 1);
        int temp = a[i];
        a[i] = a[pick];
        a[pick] = temp;
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5}, n = 5;
    Random(a, n);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}
