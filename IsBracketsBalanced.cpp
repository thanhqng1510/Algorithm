#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsBalanced(const string& brackets) {
    vector<char> v;
    v.reserve(brackets.size());
    for (int i = 0; i < brackets.size(); ++i) {
        if (const char c = brackets[i]; c == '(' || c == '{' || c == '[')
            v.emplace_back(c);
        else {
            if (v.size() == 0)
                return false;
            else if ((c == ')' && v.back() == '(') || (c == '}' && v.back() == '{') || (c == ']' && v.back() == '['))
                v.pop_back();
        }
    }
    
    return (v.size() == 0);
}

int main() {
    string brackets;
    cout << "Input brackets: ";
    cin >> brackets;
    
    cout << IsBalanced(brackets) << endl;
}
