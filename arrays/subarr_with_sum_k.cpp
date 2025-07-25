#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3};
    int k = 3;

    unordered_map<int, int> m;
    m[0] = 1;
    int sum = 0;
    int count = 0;

    for (int num : nums) {
        sum += num;
        if (m.find(sum - k) != m.end()) {
            count += m[sum - k];
        }
        m[sum]++;
    }

    cout << "Number of subarrays with sum " << k << " is: " << count << endl;

    return 0;
}
