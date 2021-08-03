/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

[Follow up]
What if the inputs contain unicode characters? How would you adapt your solution to such case?

[Answer]
Use a hash table instead of a fixed size counter. Imagine allocating a large size array to fit the entire range of unicode characters, which could go up to more than 1 million. A hash table is a more generic solution and could adapt to any range of characters.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> map;
        for (char c : s) map[c]++;

        for (char c : t)
            if (--map[c] < 0) return false;

        return true;
    }
};