#include <iostream>
using namespace std;

void Sort(int a[], int n) {         // can sort with nlogn algorithm
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

int main() {
    int a[] = {3, 6, 1, 9}, b[] = {4, 5, 8, 7}, target = 12, n = 4;
    Sort(a, n);
    Sort(b, n);
    
    int index_a = 0, index_b = n - 1;
    int smallest_diff = abs(a[index_a] + b[index_b] - target), final_a = a[index_a], final_b = b[index_b];
    while (index_a < n && index_b >= 0) {
        int cur_diff = a[index_a] + b[index_b] - target;
        if (abs(cur_diff) < smallest_diff) {
            smallest_diff = cur_diff;
            final_a = a[index_a];
            final_b = b[index_b];
        }
        
        if (cur_diff == 0)
            break;
        else if (cur_diff > 0)
            --index_b;
        else
            ++index_a;
    }
    
    cout << final_a << " " << final_b << endl;
}
