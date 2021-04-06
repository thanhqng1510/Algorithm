#include <iostream>
using namespace std;

void MaxHeapifyDown(int* const a, const int& n, const int& id) {
    if (id >= 0 && id < n / 2) {
        int i_left = 2 * id + 1, i_right = 2 * id + 2, i_max;
        
        // always have 1 or 2 children, can't have no children
        if (i_left < n && i_right < n)
            (a[i_left] > a[i_right]) ? (i_max = i_left) : (i_max = i_right);
        else if (i_left < n)
            i_max = i_left;
        else
            i_max = i_right;
        
        if (a[i_max] > a[id]) {
            int temp = a[id];
            a[id] = a[i_max];
            a[i_max] = temp;
            
            MaxHeapifyDown(a, n, i_max);
        }
    }
}

void HeapSort(int* const a, const int& n) {
    for (int i = n / 2; i >= 0; --i)
        MaxHeapifyDown(a, n, i);
    
    for (int i = n - 1; i >= 0; --i) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        
        MaxHeapifyDown(a, i, 0);
    }
}

int main() {
    int a[] = {3, 1, 6, 5, 2, 4}, n = sizeof(a) / sizeof(a[0]);
    
    HeapSort(a, n);
    
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}
