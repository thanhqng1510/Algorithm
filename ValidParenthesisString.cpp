/*
 Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

 Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 Any right parenthesis ')' must have a corresponding left parenthesis '('.
 Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
 An empty string is also valid.
 */


// ---------------------------------------


#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool CheckValidString(const string& s) {
    int n = (int)s.size();
    if (n == 0) return true;
    
    vector<vector<bool>> dp(n, vector<bool>(n));
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') dp[i][i] = true;
        if ((i < n - 1) &&
            ((s[i] == '*' || s[i] == '(') &&
             (s[i + 1] == '*' || s[i + 1] == ')'))) dp[i][i + 1] = true;
    }
    
    for (int size = 2; size < n; ++size)
        for (int i = 0; i + size < n; ++i) {
            if (s[i] == '*' && dp[i + 1][i + size]) dp[i][i + size] = true;
            else if (s[i] == '(' || s[i] == '*') {
                for (int k = i + 1; k <= i + size; ++k)
                    if ((s[k] == ')' || s[k] == '*') &&
                        (k == i + 1 || dp[i + 1][k - 1]) &&
                        (k == i + size || dp[k + 1][i + size]))
                        dp[i][i + size] = true;
            }
        }
    
    return dp[0][n - 1];
}

bool CheckValidStringGreedy(const string& s) {
    int lo = 0, hi = 0;
    for (char c : s) {
        if (c == '(') {
            ++lo;
            ++hi;
        }
        else if (c == ')') {
            --lo;
            --hi;
        }
        else {
            --lo;
            ++hi;
        }
        
        if (hi < 0)
            return false;
        
        lo = max(lo, 0);
    }
    return lo == 0;
}


int main() {
    vector<string> inputs = { "()", "(*)", "(*))" };
    for (const auto& input : inputs) {
        cout << boolalpha << "DP: " << CheckValidString(input) << "\n";
        cout << boolalpha << "Greedy: " << CheckValidString(input) << "\n";
    }
}
