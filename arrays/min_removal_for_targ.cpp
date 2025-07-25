// same as longest subarray with sum k
// 1.k=sum-target
// 2.print len(arr)-maxlen

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1,1,3,1,2};
    int t = 4;
    int sums=accumulate(v.begin(), v.end(), 0);
    int k=sums-t;
    int n = v.size();
    unordered_map<int, int> m;
    int sum = 0;
    int ml = 0;

    for (int i = 0; i < n; i++) {
        sum += v[i];
        if (sum == k) {
            ml = i + 1;
        }
        if (m.find(sum - k) != m.end()) {
            ml = max(ml, i - m[sum - k]);
        }
        if (m.find(sum) == m.end()) {
            m[sum] = i;
        }
    }

    cout << "Max length: " << n-ml << endl;
    return 0;
}