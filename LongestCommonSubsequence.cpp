// https://www.ics.uci.edu/~eppstein/161/960229.html

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Max(const int& a, const int& b) {
    return (a > b) ? a : b;
}

int LCS(const string& a, const string& b, int i, int j) {
    if (a[i] == '\0' || b[j] == '\0')
        return 0;
    else if (a[i] == b[j])
        return 1 + LCS(a, b, i + 1, j + 1);
    return Max(LCS(a, b, i + 1, j), LCS(a, b, i, j + 1));
}

int LCS_Memoi(const string& a, const string& b, int i, int j, int** const res) {
    if (res[i][j] < 0) {
        if (a[i] == '\0' || b[j] == '\0')
            res[i][j] = 0;
        else if (a[i] == b[j])
            res[i][j] = 1 + LCS_Memoi(a, b, i + 1, j + 1, res);
        else
            res[i][j] = Max(LCS_Memoi(a, b, i + 1, j, res), LCS_Memoi(a, b, i, j + 1, res));
    }
    return res[i][j];
}

auto LCS_BottomUp(const string& a, const string& b) {
    int row = (int)a.length() + 1, col = (int)b.length() + 1;
    int** res = new int* [row];
    for (int i = 0; i < row; ++i)
        res[i] = new int [col];
    
    for (int i = row - 1; i >= 0; --i)
        for (int j = col - 1; j >= 0; --j) {
            if (a[i] == '\0' || b[j] == '\0')
                res[i][j] = 0;
            else if (a[i] == b[j])
                res[i][j] = 1 + res[i + 1][j + 1];
            else
                res[i][j] = Max(res[i + 1][j], res[i][j + 1]);
        }
    int temp = res[0][0];
    
    vector<char> lcs;
    int i_r = 0, i_c = 0;
    while (i_r < row - 1 && i_c < col - 1) {    // can not check '\0' so we have to - 1
        if (res[i_r][i_c] != res[i_r + 1][i_c] && res[i_r][i_c] != res[i_r][i_c + 1]) {
            lcs.emplace_back(a[i_r]);
            ++i_r;
            ++i_c;
        }
        else {
            if (res[i_r][i_c] == res[i_r + 1][i_c] && res[i_r][i_c] == res[i_r][i_c + 1]) {
                ++i_r;
                ++i_c;
            }
            else if (res[i_r][i_c] != res[i_r + 1][i_c])
                ++i_c;
            else
                ++i_r;
        }
    }
    
    for (int i = 0; i < row; ++i)
        delete [] res[i];
    delete [] res;
    
    struct result {
        int num;
        vector<char> lcs;
    };
    
    return result{temp, lcs};
}

int main() {
    string a = "quy thanh", b = "tam phuc";
    
    int row = (int)a.length() + 1, col = (int)b.length() + 1;
    int** res = new int* [row];
    for (int i = 0; i < row; ++i)
        res[i] = new int [col];
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            res[i][j] = -1;
    
    vector<char> lcs;
    cout << LCS_Memoi(a, b, 0, 0, res) << endl;
    int i_r = 0, i_c = 0;
    while (i_r < row - 1 && i_c < col - 1) {    // can not check '\0' in string a and b so we have to - 1
        if (res[i_r][i_c] != res[i_r + 1][i_c] && res[i_r][i_c] != res[i_r][i_c + 1]) {
            lcs.emplace_back(a[i_r]);
            ++i_r;
            ++i_c;
        }
        else {
            if (res[i_r][i_c] == res[i_r + 1][i_c] && res[i_r][i_c] == res[i_r][i_c + 1]) {
                ++i_r;
                ++i_c;
            }
            else if (res[i_r][i_c] != res[i_r + 1][i_c])
                ++i_c;
            else
                ++i_r;
        }
    }
    for (int i = 0; i < lcs.size(); ++i)
        cout << lcs[i];
    cout << endl;
    lcs.clear();
    
    auto [num, _lcs] = LCS_BottomUp(a, b);
    cout << num << endl;
    for (const char& temp : _lcs)
        cout << temp;
    cout << endl;
    
    cout << LCS(a, b, 0, 0) << endl;
    
    for (int i = 0; i < row; ++i)
        delete [] res[i];
    delete [] res;
}
