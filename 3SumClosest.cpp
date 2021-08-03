/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int absDiff = INT_MAX;
        int result;
        
        for (int i = 0; i < n; ++i) {
            int first = i + 1, last = n - 1;

            while (first < last) {
                int curDiff = nums[first] + nums[last] + nums[i] - target;
                if (abs(curDiff) < absDiff) {
                    absDiff = abs(curDiff);
                    result = nums[first] + nums[last] + nums[i];
                }

                if (curDiff == 0) return result;
                if (curDiff > 0) --last;
                else ++first;
            }
        }

        return result;
    }
};