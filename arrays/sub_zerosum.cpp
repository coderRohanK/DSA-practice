#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = v.size();
    unordered_map<int, int> m;
    int sum = 0;
    int maxLen = 0;
    m[0] = -1;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        if (m.find(sum) != m.end()) {
            maxLen = max(maxLen, i - m[sum]);
        } else {
            m[sum] = i;
        }
    }
    cout << maxLen << endl;
    return 0;
}
