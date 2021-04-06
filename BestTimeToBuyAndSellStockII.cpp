/*
 Say you have an array prices for which the ith element is the price of a given stock on day i.

 Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

 Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 */


// ---------------------------------------


#include <iostream>
#include <vector>
using namespace std;


int MaxProfit(const vector<int>& prices) {
    int n = (int)prices.size();
    int profit = 0;
    
    for (int i = 1; i < n; ++i)
        if (prices[i] > prices[i - 1])
            profit += (prices[i] - prices[i - 1]);
    // if price go up, just wait to the highest price and sell
    // if price go down, sell on prev day and buy on this day
    
    return profit;
}

int MaxProfitDP(const vector<int>& prices) {    // works when you can have more than 1 stock at a time
    int n = (int)prices.size();
    const int NINF = -1e5;
    vector<vector<int>> dp(n + 1, vector<int>(2));    // dp[d][s]: max amount of money when you have s stock on d day
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
        dp[i][1] = NINF;
    }
    
    for (int day = 1; day <= n; ++day) {
        dp[day][1] = max(dp[day - 1][1], dp[day - 1][0] - prices[day - 1]);
        dp[day][0] = max(dp[day - 1][0], dp[day - 1][1] + prices[day - 1]);
    }
    
    return dp[n][0];
}

int MaxProfitDPUpgrade(const vector<int>& prices) {
    const int NINF = -1e5;
    int best_without_stock = 0, best_with_stock = NINF;
    
    for (int i : prices) {
        best_with_stock = max(best_with_stock, best_without_stock - i);
        best_without_stock = max(best_without_stock, best_with_stock + i);
    }
    
    return best_without_stock;
}


int main() {
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };
    
    cout << MaxProfit(prices) << "\n";
    cout << MaxProfitDP(prices) << "\n";
    cout << MaxProfitDPUpgrade(prices) << "\n";
}
