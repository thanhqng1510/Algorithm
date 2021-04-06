#include <iostream>
using namespace std;

const int n = 5;

void Rotate(int a[][n]) {
    for (int layer = 0; layer < n / 2; ++layer) {
        int i_start = layer, i_stop = n - 2 - layer, range = i_stop - i_start + 1;
        for (int i = 0; i < range; ++i) {
            int temp = a[i_start][i_start + i];
            a[i_start][i_start + i] = a[i_start + range - i][i_start];
            a[i_start + range - i][i_start] = a[i_start + range][i_stop + 1 - i];
            a[i_start + range][i_stop + 1 - i] = a[i_start + i][i_stop + 1];
            a[i_start + i][i_stop + 1] = temp;
        }
    }
}

int main() {
    int a[n][n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            a[i][j] = i + j;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
    
    Rotate(a);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}
