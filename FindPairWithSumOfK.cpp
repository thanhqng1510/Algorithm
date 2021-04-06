#include <iostream>

auto IsExisted(int* const a, const int& n, const int& k) {
    // sorting
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    
    int id0 = 0, id1 = n - 1, sum = a[id0] + a[id1];
    while (sum != k && id0 < id1) {
        (sum > k) ? --id1 : ++id0;
        sum = a[id0] + a[id1];
    }
    
    struct result {
        bool is_existed;
        int num0, num1;
    };
    return result{ (id0 < id1), a[id0], a[id1] };
}

int main() {
    int a[] = {10, 6, 5, 7, 9, 10}, n = sizeof(a) / sizeof(a[0]), k = 20;
    
    auto [is_existed, num0, num1] = IsExisted(a, n, k);
    std::cout << is_existed << " " << num0 << " " << num1 << std::endl;
}
