/*
	Determine whether a singly linked list is palindrome or not.
*/


// ---------------------------------------------------------


#include <list>
#include <iostream>
using namespace std;


typedef list<int>::const_iterator c_iter;
typedef const list<int>& cref_list;


auto _isPalindromeHelper(cref_list l, c_iter start, c_iter end, c_iter fast, c_iter& mirrorStart) { 
	if (fast == end) {
		mirrorStart = start;
		return true;
	}
	if (next(fast) == end) {
		if (fast == start) mirrorStart = start;
		else mirrorStart = ++start;
		return true;
	}

	auto res = _isPalindromeHelper(l, next(start), end, next(fast, 2), mirrorStart);
	if (!res || *start != *mirrorStart) return false;
	++mirrorStart;
	return true;
}

auto isPalindrome(cref_list l, c_iter begin, c_iter end) {
	c_iter mirrorStart = l.begin();
	return _isPalindromeHelper(l, l.begin(), l.end(), l.begin(), mirrorStart);
}


int main() {
	list<int> l { 0, 1, 2, 3, 4, 3, 2, 1, 0 };
	cout << boolalpha << isPalindrome(l, l.begin(), l.end()) << "\n";
}