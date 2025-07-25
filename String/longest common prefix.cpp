#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";
    string pre = strs[0];
    int n = strs.size();
    for(int i = 1; i < n; i++) {
        int j = 0;
        while(j < strs[i].length() && j < pre.length()) {
            if(strs[i][j] == pre[j]) {
                j++;
            } else {
                break;
            }
        }
        pre = pre.substr(0, j);
        if(pre == "") return "";
    }
    return pre;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs) << endl;
    return 0;
}
