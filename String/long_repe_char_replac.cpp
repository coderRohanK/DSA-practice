#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int characterReplacement(string s, int k) {
    int l = 0;
    int r = 0;
    int ma = 0;
    int ans = 0;
    unordered_map<char, int> m;

    while (r < s.length()) {
        m[s[r]]++;
        ma = max(ma, m[s[r]]);
        int len = r - l + 1;
        if (len - ma <= k) {
            ans = max(ans, len);
        } else {
            m[s[l]]--;
            l++;
        }
        r++;
    }

    return ans;
}

int main() {
    string s = "AABABBA";
    int k = 1;
    int result = characterReplacement(s, k);
    cout << "Longest repeating character replacement: " << result << endl;
    return 0;
}