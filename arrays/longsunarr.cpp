#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {10, 5, 1, 7, 7};
    int k = 15;
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

    cout << "Max length: " << ml << endl;
    return 0;
}

// application
// 1.daily electricity usage adds up to exactly 100 kWh
// 2. longest streak of days where your daily expenses sum up to exactly ₹5,000 
// 3.longest consecutive days where a user’s calorie intake sums to 14,000 kcal
// 4.longest period during which the sum of daily temperature anomalies adds to zero
// 5.longest streak of days where the profit/loss totals to ₹0