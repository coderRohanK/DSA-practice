#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {2, 1, 5, 3};
    int k = 8;
    int n = v.size();
    for (int i = 0; i < n - 2; i++) {
        unordered_map<int, int> m;
        for (int j = i + 1; j < n; j++) {
            int rem = k - v[i] - v[j];
            if (m.find(rem) != m.end()) {
                cout << i << "," << m[rem] << "," << j << endl;
            }
            m[v[j]] = j;
        }
    }
    return 0;
}
