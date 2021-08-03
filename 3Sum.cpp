/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<vector<int>> result;

        for (int i = 0; i < nums.size(); ++i) {
            int first = i + 1, last = nums.size() - 1;

            while (first < last) {
                if (nums[first] + nums[last] + nums[i] == 0) {
                    result.insert({nums[i], nums[first], nums[last]});
                    ++first;
                    --last;
                }
                else if (nums[first] + nums[last] > -nums[i])
                    --last;
                else
                    ++first;
            }
        }

        return {
            make_move_iterator(result.begin()),
            make_move_iterator(result.end())
        };
    }
};