#include <iostream>


void quickSort(int* a, int left, int right) {
    if (left >= right)
        return;

    int pivot = a[(left + right) / 2];
    int i = left, j = right;

    while (i < j) {
        while (a[i] < pivot)
            ++i;
        while (a[j] > pivot)
            --j;

        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            ++i;
            --j;
        }
    }

    quickSort(a, left, j);
    quickSort(a, i, right);
}

int main() {
    int a[] = { 12, 2, 15, -3, 8, 5, 1, -8, 6, 0, 4, 15, 9 };
    int n = sizeof(a) / sizeof(a[0]);

    quickSort(a, 0, n - 1);
    for (int i : a)
        std::cout << i << " ";
}