#include <iostream>
using namespace std;

int NextFit(int* weight, int n, int bin_capacity) {
    int num_bin = 1, cur_bin_capacity = bin_capacity;
    
    for (int i = 0; i < n; ++i) {
        if (weight[i] > cur_bin_capacity) {
            ++num_bin;
            cur_bin_capacity = bin_capacity - weight[i];
        }
        else
            cur_bin_capacity -= weight[i];
    }
    
    return num_bin;
}

int FirstFit(int* weight, int n, int bin_capacity) {
    int bins_capacity[n];
    int num_bin = 1;
    bins_capacity[0] = bin_capacity;
    
    for (int i = 0; i < n; ++i) {
        int cur_bin;
        for (cur_bin = 0; cur_bin < num_bin; ++cur_bin)
            if (weight[i] <= bins_capacity[cur_bin]) {
                bins_capacity[cur_bin] -= weight[i];
                break;
            }
        
        if (cur_bin == num_bin) {
            ++num_bin;
            bins_capacity[num_bin - 1] = bin_capacity - weight[i];
        }
    }
    
    return num_bin;
}

int BestFit(int* weight, int n, int bin_capacity) {
    int bins_capacity[n];
    int num_bin = 1;
    bins_capacity[0] = bin_capacity;
    
    for (int i = 0; i < n; ++i) {
        int cur_bin;
        int min = bin_capacity + 1, best_bin = 0;
        
        for (cur_bin = 0; cur_bin < num_bin; ++cur_bin)
            if (weight[i] <= bins_capacity[cur_bin] && bins_capacity[cur_bin] - weight[i] < min) {
                min = bins_capacity[cur_bin] - weight[i];
                best_bin = cur_bin;
                
                if (min == 0)
                    break;
            }
        
        if (min == bin_capacity + 1) {      // no bin big enough to put into
            ++num_bin;
            bins_capacity[num_bin - 1] = bin_capacity - weight[i];
        }
        else
            bins_capacity[best_bin] -= weight[i];
    }
    return num_bin;
}

int FirstFitDecreasing(int* weight, int n, int bin_capacity) {
    sort(weight, weight + n, greater<int>());
    
    return FirstFit(weight, n, bin_capacity);
}

int main() {
    int weight[] = {2, 5, 4, 7, 1, 3, 8}, n = 7, bin_capacity = 10;
    
    // Check if it fits in the same bin as the last item, use a new bin only if it does not
    // Requires only O(n) time and O(1) extra space to process n items
    // Next Fit uses at most 2M bins if M is optimal
    cout << "Next fit: " << NextFit(weight, n, bin_capacity) << endl;
    
    // See if a new item fits in any other bins, start a new bin only if it does not
    // Requires O(n2) time, but can be implemented in O(nLogn) time using Self-Balancing Binary Search Trees
    // Never uses more than 1.7M bins
    cout << "First fit: " << FirstFit(weight, n, bin_capacity) << endl;
    
    // Put the item in the bin so that smallest empty space is left, start a new bin if no bins are big enough
    // Best Fit can also be implemented in O(n Log n) time using Self-Balancing Binary Search Trees
    // Never uses more than 1.7M bins
    cout << "Best fit: " << BestFit(weight, n, bin_capacity) << endl;
    
    // Sorting the input sequence, and placing the large items first
    // First Fit Decreasing produces the best result for the sample input because items are sorted first
    // First Fit Decreasing can also be implemented in O(nLogn) time using Self-Balancing Binary Search Trees.
    cout << "First fit decreasing: " << FirstFitDecreasing(weight, n, bin_capacity) << endl;
}
