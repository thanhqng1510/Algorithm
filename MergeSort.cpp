#include <iostream>


void merge(int* a, int left, int mid, int right) {
    int* temp = (int*)alloca((right - left + 1) * sizeof(int));
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
        a[i] < a[j] ? temp[k++] = a[i++] : temp[k++] = a[j++];
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= right)
        temp[k++] = a[j++];

    for (int i = 0; i < right - left + 1; ++i)
        a[left + i] = temp[i];
}

void mergeSort(int* a, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main() {
    int a[] = { 12, 2, 15, -3, 8, 5, 1, -8, 6, 0, 4, 15, 9 };
    int n = sizeof(a) / sizeof(a[0]);

    mergeSort(a, 0, n - 1);
    for (int i : a)
        std::cout << i << " ";
}