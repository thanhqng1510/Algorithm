/*
 Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

 Follow up:
 Could you solve it in linear time?
 */


// --------------------------------------


#include <iostream>
#include <vector>
#include <deque>
using namespace std;


vector<int> MaxSlidingWindow(const vector<int>& nums, int k) {
    int n = (int)nums.size();
    vector<int> res;
    deque<int> dq;
    
    for (int i = 0; i < k; ++i) {
        while (!dq.empty() && nums[i] > dq.back())
            dq.pop_back();
        dq.push_back(nums[i]);
    }
    
    res.push_back(dq.front());
    
    for (int i = 1; i < n - k + 1; ++i) {
        int to_rm = nums[i - 1];    // remove i - 1
        if (to_rm == dq.front())
            dq.pop_front();
        
        int to_add = nums[i + (k - 1)];    // add i + (k - 1)
        while (!dq.empty() && to_add > dq.back())
            dq.pop_back();
        dq.push_back(to_add);
        
        res.push_back(dq.front());
    }
    
    return res;
}


int main(int argc, const char * argv[]) {
    vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k = 3;
    
    auto res = MaxSlidingWindow(nums, k);
    for (int i : res)
        cout << i << " ";
    cout << "\n";
}
