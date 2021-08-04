/*
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int first = INT_MAX, last = INT_MIN;

		// Using monotonic stack to find the first and last violation element in the array

		// Finding the first violation
        stack<int> increasing;
        for (int i = 0; i < n; ++i) {
            while (!increasing.empty() && nums[i] < nums[increasing.top()]) {
                first = min(first, increasing.top());
                increasing.pop();
            }
            increasing.push(i);
        }

		// Finding the last violation
        stack<int> decreasing;
        for (int i = n - 1; i >= 0; --i) {
            while (!decreasing.empty() && nums[i] > nums[decreasing.top()]) {
                last = max(last, decreasing.top());
                decreasing.pop();
            }
            decreasing.push(i);
        }

        return last > first ? last - first + 1 : 0;
    }
};