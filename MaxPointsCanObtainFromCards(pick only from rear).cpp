/*
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array card_points.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array card_points and the integer k, return the maximum score you can obtain.
*/



// ---------------------------------------------


#include <iostream>
#include <vector>
using namespace std;


int MaxScore(const vector<int>& card_points, int k) {
    int n = (int)card_points.size();
    int min = 0, left_i = 0, right_i = n - 1 - k;
    
    for (int i = left_i; i <= right_i; ++i)
        min += card_points[i];
    int cur = min;
    
    while (right_i + 1 < n) {
        cur = cur - card_points[left_i++] + card_points[++right_i];
        if (cur < min)
            min = cur;
    }
    
    int sum = 0;
    for (int i : card_points)
        sum += i;
    return sum - min;
}


int main(int argc, const char * argv[]) {
    vector<int> card_points = { 1, 2, 3, 4, 5, 6, 1 };
    int k = 3;
    cout << MaxScore(card_points, k) << "\n";
}
