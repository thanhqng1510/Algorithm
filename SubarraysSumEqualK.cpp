/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
 */


// ----------------------------------


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int SubarraySum(const vector<int>& nums, int k) {
    int n = (int)nums.size();
    int cur_pref = 0;
    int res = 0;
    unordered_map<int, int> cnt_pref;   // map from needed value to how many pref sums satisfy
    ++cnt_pref[cur_pref];
    for (int r = 0; r < n; ++r) {
        cur_pref += nums[r];
        int need = cur_pref - k;
        res += cnt_pref[need];
        ++cnt_pref[cur_pref];
    }
    return res;
}


int main(int argc, const char * argv[]) {
    vector<int> nums = { 1, 1, 1 };
    int k = 2;
    cout << SubarraySum(nums, k) << "\n";
}
