#include <iostream>


void countingSort(int* a, int n) {
    int time_occur[10];
    std::fill(time_occur, time_occur + 10, 0);

    for (int i = 0; i < n; ++i)
        ++time_occur[a[i]];
    for (int i = 1; i < 10; ++i)
        time_occur[i] += time_occur[i - 1];

    int* temp = (int*)alloca(n * sizeof(int));
    for (int i = n - 1; i >= 0; --i)
        temp[--time_occur[a[i]]] = a[i];

    std::copy(temp, temp + n, a);
}

int main() {
    int a[] = { 1, 6, 5, 4, 4, 7, 6, 2, 6, 7, 8, 2, 4, 1, 0 };
    int n = sizeof(a) / sizeof(a[0]);

    countingSort(a, n);
    for (int i : a)
        std::cout << i << " ";
}