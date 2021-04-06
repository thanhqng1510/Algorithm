/*
 Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
 */


// ------------------------------------------


#include <iostream>
#include <vector>
using namespace std;


int MaximalSquare2D(const vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty())
        return 0;
    
    int R = (int)matrix.size(), C = (int)matrix[0].size();
    vector<vector<int>> dp(R, vector<int>(C, 0));   // the maximum square that bottom right ends in this [r][c]
    int max_side = 0;
    
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c) {
            if (matrix[r][c] == '1') {
                dp[r][c] = 1;
                if (r > 0 && c > 0)
                    dp[r][c] += min({ dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1] });
                
                max_side = max(max_side, dp[r][c]);
            }
        }
            
    return max_side * max_side;
}

int MaximalSquare1D(const vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty())
        return 0;
    
    int R = (int)matrix.size(), C = (int)matrix[0].size();
    vector<int> dp(C + 1);    // the maximum square that bottom right ends in this [r(dynamic)][c]
    int max_side = 0, prev = 0;
    
    for (int r = 1; r <= R; ++r) {   // for loop to fill dp
        for (int c = 1; c <= C; ++c) {
            int temp = dp[c];
            if (matrix[r - 1][c - 1] == '1') {
                dp[c] = 1 + min({ dp[c], dp[c - 1], prev });
                
                max_side = max(max_side, dp[c]);
            }
            else
                dp[c] = 0;
            prev = temp;
        }
    }
            
    return max_side * max_side;
}


int main(int argc, const char * argv[]) {
    vector<vector<char>> matrix = {
        { '1', '0', '1', '0', '0' },
        { '1', '0', '1', '1', '1' },
        { '1', '1', '1', '1', '1' },
        { '1', '0', '0', '1', '0' }
    };
    
    cout << MaximalSquare2D(matrix) << "\n";
    cout << MaximalSquare1D(matrix) << "\n";
}
