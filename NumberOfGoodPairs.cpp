/*
 Given an array of integers nums.
 A pair (i,j) is called good if nums[i] == nums[j] and i < j.
 Return the number of good pairs.
 */


// --------------------------------


#include <iostream>
#include <vector>
#include <unordered_map>


int NumIdenticalPairs(const std::vector<int>& nums) {
    int res = 0;
    std::unordered_map<int, int> map;
    
    for (int i : nums) {
        if (map.find(i) == map.end())
            map[i] = 1;
        else {
            res += map[i];
            map[i] += 1;
        }
    }
    
    return res;
}


int main() {
    std::vector<int> v = { 1, 2, 3, 1, 1, 3 };
    std::cout << NumIdenticalPairs(v) << "\n";
}
