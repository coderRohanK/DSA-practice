#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abcabcbb";
    int i = 0, j = 0;
    int len = 0, maxlen = 0;
    unordered_map<char, int> m;

    while (j < s.size()) {
        if (m.find(s[j]) == m.end() || m[s[j]] == 0) {
            m[s[j]]++;
            len = j - i + 1;
            maxlen = max(maxlen, len);
            j++;
        } else {
            m[s[i]]--;
            i++;
        }
    }
    cout << maxlen;
    return 0;
}

// ✅ Time Complexity
// O(n)
// Each character is visited at most twice (once by j and once by i).

// ✅ Space Complexity
// O(min(n, m))
// Where n is the string length, m is the size of the character set.
// Here, worst case is O(m) if all characters are unique (i.e. storing up to all distinct characters in the map).