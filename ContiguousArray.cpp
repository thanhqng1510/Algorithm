/*
 Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.
 */


// ---------------------------------------------


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


typedef pair<int, int> pair_int;

int FindMaxLength(const vector<int>& nums) {
    int n = (int)nums.size();
    int sum = 0;
    int max_len = 0;
    unordered_map<int, int> map;    // map from first sum (if there are same sum) to index (0 as -1, 1 as +1)
    map[0] = -1;    // use when sum = 0, i - (-1) = i + 1 = actual length
    
    for (int i = 0; i < n; ++i) {
        sum += (nums[i] == 0 ? -1 : 1);
        
        auto it = map.find(sum);
        if (it != map.end())
            max_len = max(max_len, i - it->second);
        else
            map[sum] = i;   // if there are many same cnt, only save the left-most
    }
    
    return max_len;
}


int main() {
    vector<int> nums = { 1, 0, 0, 0, 1, 1, 1, 0 };
    cout << FindMaxLength(nums) << "\n";
}
