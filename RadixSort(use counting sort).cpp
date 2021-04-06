#include <iostream>


void radixSort(int* a, int n) {
    int max = *std::max_element(a, a + n);
    int exp = 1;

    while (max / exp > 0) {
        int time_occur[10];
        std::fill(time_occur, time_occur + 10, 0);

        for (int i = 0; i < n; ++i)
            ++time_occur[a[i] / exp % 10];
        for (int i = 1; i < 10; ++i)
            time_occur[i] += time_occur[i - 1];

        int *temp = (int *) alloca(n * sizeof(int));
        for (int i = n - 1; i >= 0; --i)
            temp[--time_occur[a[i] / exp % 10]] = a[i];

        std::copy(temp, temp + n, a);

        exp *= 10;
    }
}

int main() {
    int a[] = { 15, 600, 345, 1, 4, 564, 34, 765, 54, 2 };
    int n = sizeof(a) / sizeof(a[0]);

    radixSort(a, n);
    for (int i : a)
        std::cout << i << " ";
}