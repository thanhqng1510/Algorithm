/*
 Given an array of integers nums and an integer limit, return the size of the longest continuous subarray such that the absolute difference between any two elements is less than or equal to limit.

 In case there is no subarray satisfying the given condition return 0.
 */


// --------------------------------------


#include <iostream>
#include <vector>
#include <deque>
using namespace std;


int LongestSubarray(const vector<int>& nums, int limit) {
    if (limit < 0)
        return 0;
    
    int n = (int)nums.size();
    int res = 0;
    deque<int> max_dq, min_dq;
            
    int l = 0;
    for (int r = 0; r < n; ++r) {
        while (!max_dq.empty() && nums[r] > max_dq.back())
            max_dq.pop_back();
        max_dq.push_back(nums[r]);

        while (!min_dq.empty() && nums[r] < min_dq.back())
            min_dq.pop_back();
        min_dq.push_back(nums[r]);
        
        while (max_dq.front() - min_dq.front() > limit) {
            if (nums[l] == max_dq.front())
                max_dq.pop_front();
            if (nums[l] == min_dq.front())
                min_dq.pop_front();
            ++l;
        }
        
        int len = r - l + 1;
        if (len > res)
            res = len;
    }
    
    return res;
}


int main(int argc, const char * argv[]) {
    vector<int> nums = { 8, 2, 4, 7 };
    int limit = 4;
    
    cout << LongestSubarray(nums, limit) << "\n";
}
