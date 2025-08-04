#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backtrack(int open, int close, string curr, vector<string>& result) {
    if (open == 0 && close == 0) {
        result.push_back(curr);
        return;
    }
    if (open > 0) {
        backtrack(open - 1, close, curr + "(", result);
    }
    if (close > open) {
        backtrack(open, close - 1, curr + ")", result);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    backtrack(n, n, "", result);
    return result;
}

int main() {
    int n = 3;
    vector<string> res = generateParenthesis(n);
    for (string s : res) {
        cout << s << endl;
    }
    return 0;
}
