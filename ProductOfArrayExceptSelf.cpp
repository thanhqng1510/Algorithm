/*
 Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

 Example:
 Input:  [1,2,3,4]
 Output: [24,12,8,6]
 
 Note: Please solve it without division and in O(n).

 Follow up:
 Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
 */


// ----------------------------------------


#include <iostream>
#include <vector>
using namespace std;


vector<int> ProductExceptSelf(const vector<int>& nums) {
    int n = (int)nums.size();
    vector<int> res(n, 1);
    
    int cur_pref = 1;
    for (int i = 1; i < n; ++i) {  // pour from left -> right
        cur_pref *= nums[i - 1];
        res[i] *= cur_pref;
    }
    
    int cur_suff = 1;
    for (int i = n - 2; i >= 0; --i) {  // pour from right -> left
        cur_suff *= nums[i + 1];
        res[i] *= cur_suff;
    }
    
    return res;
}


int main(int argc, const char * argv[]) {
    vector<int> nums = { 1, 2, 3, 4 };
    auto res = ProductExceptSelf(nums);
    for (int i : res)
        cout << i << " ";
    cout << "\n";
}
