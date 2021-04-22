/*
	Given a set of closed intervals, find the smallest set of numbers that covers all the intervals. If there are multiple smallest sets, return any of them.

	For example, given the intervals [0, 3], [2, 6], [3, 4], [6, 9], one set of numbers that covers all these intervals is {3, 6}.
*/


// --------------------------------------------


#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

typedef std::pair<int, int> interval;


std::set<int> process(std::vector<interval> intervals) {
	if (intervals.empty()) return std::set<int>();

	std::sort(intervals.begin(), intervals.end(), [](const interval& a, const interval& b) {
		return a.first < b.first;
   	});
	int right = intervals[0].second;
	std::set<int> result;

	for (int i = 1; i < intervals.size(); ++i) {
		if (intervals[i].first <= right) right = std::min(right, intervals[i].second);
		else {
			result.insert(right);
			right = intervals[i].second;
		}
	}
	result.insert(right);

	return result;
}


int main() {
	std::vector<interval> input = { { 0, 3 }, { 2, 6 }, { 3, 4 }, { 6, 9 } };
	std::set<int> result = process(input);
	for (int e : result) std::cout << e << " ";
	std::cout << "\n";
}
