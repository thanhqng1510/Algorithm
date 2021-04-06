/*
 In how many ways can you tile a (3 x n) rectangle with some (2 x 1) dominoes?
 Input consists of several test cases followed by a line containing -1. Each test case is a line containing an integer n (0 <= n <= 30)
 */


// -------------------------------------------------


#include <iostream>
#include <vector>
using namespace std;


int TriTiling(int n) {
    if ((n & 1) == 1)    // n is an odd number
        return 0;
    
    int states = 8;    // 8 states to fill a column (partial to full)
    /*
     state 0        state 2        state 4        state 6
     |              |              |              |
     |              |--            |              |--
     |              |              |--            |--
     state 1        state 3        state 5        state 7
     |--            |--            |--            |--
     |              |--            |              |--
     |              |              |--            |--
     */
    vector<vector<int>> dp(n + 1, vector<int>(states, 0));    // dp of (n + 1) column and 8 states
    dp[0][7] = 1;
    
    for (int i = 1; i <= n; ++i) {
        dp[i][0] += dp[i - 1][7];
        dp[i][1] += dp[i - 1][6];
        dp[i][2] += dp[i - 1][5];
        dp[i][3] += (dp[i - 1][7] + dp[i - 1][4]);
        dp[i][4] += dp[i - 1][3];
        dp[i][5] += dp[i - 1][2];
        dp[i][6] += (dp[i - 1][7] + dp[i - 1][1]);
        dp[i][7] += (dp[i - 1][6] + dp[i - 1][3] + dp[i - 1][0]);
    }
    
    return dp[n][7];
}

int TriTilingFormula(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
      
    for (int i = 4; i <= n; ++i)
        dp[i] = 4 * dp[i - 2] - dp[i - 4];
    
    return dp[n];
}


int main() {
    while (true) {
        int n;
        cin >> n;
        
        if (n == -1)
            break;
        
        cout << TriTiling(n) << "\n";
        // cout << TriTilingFormula(n) << "\n";
    }
}
