/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.
 */


// -----------------------------------------


#include <iostream>
#include <vector>
using namespace std;


bool CanJump(const vector<int>& nums) {
    int n = (int)nums.size();
    
    if (n <= 1)
        return true;    // 0 jump
    
    int can_reach = 0;
    for (int i = 0; i <= can_reach; ++i) {
        can_reach = max(can_reach, i + nums[i]);
        if (can_reach >= n - 1)
            return true;
    }
    
    return false;
}


pair<bool, int> CanJumpMinimumStep(const vector<int>& nums) {
    int n = (int)nums.size();
    
    if (n <= 1)
        return { true, 0 };
    
    int can_reach = 0, step = 0;
    for (int i = 0; i <= can_reach; ++i) {
        ++step;
        can_reach = max(can_reach, i + nums[i]);
        if (can_reach >= n - 1)
            return { true, step };
    }
    
    return { false, step };
}


int main(int argc, const char * argv[]) {
    vector<int> nums = { 2, 3, 1, 1, 4 };
    
    cout << boolalpha << CanJump(nums) << "\n";
    
    auto res = CanJumpMinimumStep(nums);
    cout << boolalpha << res.first << " " << res.second << "\n";
}
