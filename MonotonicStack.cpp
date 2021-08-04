/*
Give you an array, and return an array of equal length. The corresponding index stores the next larger element, if there is no larger element, store -1.

Let's take a direct example:
Give you an array [2,1,2,4,3], and you return an array [4,2,4,-1,-1].
*/

class Solution {
	vector<int> nextLargerElement(const vector<int>& nums) {
		int n = nums.size();

		vector<int> result(n);
		stack<int> largerElems;

		for (int i = n - 1; i >= 0; --i) {
			while (!largerElems.empty() && largerElems.top() <= nums[i])
				largerElems.pop();
			result[i] = largerElems.empty() ? -1 : largerElems.top();
			largerElems.push(nums[i]);
		}

		return result;
	}
}