/*
 Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

 Note that after backspacing an empty text, the text will continue empty.
 */


// -------------------------------------------


#include <iostream>
#include <string>
using namespace std;


bool BackspaceCompare(const string& S, const string& T) {
    int i = (int)S.size() - 1, cnt_i = 0;
    int j = (int)T.size() - 1, cnt_j = 0;
    
    while (i >= 0 || j >= 0) {
        while (i >= 0) {
            if (S[i] == '#') {
                ++cnt_i;
                --i;
            }
            else if (cnt_i > 0) {
                --cnt_i;
                --i;
            }
            else break;
        }
        
        while (j >= 0) {
            if (T[j] == '#') {
                ++cnt_j;
                --j;
            }
            else if (cnt_j > 0) {
                --cnt_j;
                --j;
            }
            else break;
        }
        
        if (i >= 0 && j >= 0 && S[i] != T[j])
            return false;
        
        if ((i >= 0) != (j >= 0))
            return false;
        
        --i; --j;
    }
    
    return true;
}

bool BackspaceCompareStack(const string& S, const string& T) {
    string s, t;
    
    for (char c : S) {
        if (c == '#') {
            if (!s.empty()) s.pop_back();
        }
        else
            s += c;
    }
    
    for (char c : T) {
        if (c == '#') {
            if (!t.empty()) t.pop_back();
        }
        else
            t += c;
    }
    
    return s == t;
}


int main() {
    string S = "ab#c", T = "ad#c";
    cout << boolalpha << BackspaceCompare(S, T) << "\n";
    cout << boolalpha << BackspaceCompareStack(S, T) << "\n";
}
