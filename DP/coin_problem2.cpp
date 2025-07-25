#include <bits/stdc++.h>
using namespace std;

int change(int amount, vector<int>& coins) {
    vector<int> dp(amount+1, 0);
    dp[0] = 1;

    for(int coin : coins) {
        for(int i=coin; i<=amount; i++) {
            dp[i] += dp[i-coin];
        }
    }
    return dp[amount];
}

int main() {
    vector<int> coins = {1,2,5};
    int amount = 5;
    cout << change(amount, coins);
    return 0;
}

// Let’s trace each iteration step by step for

// coins = {1,2,5}, amount = 5

// Initialize
// dp = [1,0,0,0,0,0]
// Processing coin = 1
// i	dp[i] += dp[i-1]	Updated dp
// 1	dp[1]=0+dp[0]=1	[1,1,0,0,0,0]
// 2	dp[2]=0+dp[1]=1	[1,1,1,0,0,0]
// 3	dp[3]=0+dp[2]=1	[1,1,1,1,0,0]
// 4	dp[4]=0+dp[3]=1	[1,1,1,1,1,0]
// 5	dp[5]=0+dp[4]=1	[1,1,1,1,1,1]

// ✅ Meaning after coin=1: Only 1 way to make each sum (using 1s repeatedly).

// Processing coin = 2
// i	dp[i] += dp[i-2]	Updated dp
// 2	dp[2]=1+dp[0]=1+1=2	[1,1,2,1,1,1]
// 3	dp[3]=1+dp[1]=1+1=2	[1,1,2,2,1,1]
// 4	dp[4]=1+dp[2]=1+2=3	[1,1,2,2,3,1]
// 5	dp[5]=1+dp[3]=1+2=3	[1,1,2,2,3,3]

// ✅ Meaning after coin=2:

// Ways to make 2: [1+1], [2] → total 2

// Ways to make 3: [1+1+1], [1+2] → total 2

// Ways to make 4: [1+1+1+1], [1+1+2], [2+2] → total 3

// Ways to make 5: [1+1+1+1+1], [1+1+2+1], [2+1+2] → total 3

// Processing coin = 5
// i	dp[i] += dp[i-5]	Updated dp
// 5	dp[5]=3+dp[0]=3+1=4	[1,1,2,2,3,4]

// ✅ Meaning after coin=5: Adds one new way for amount=5 (using coin 5 directly).

// Final dp array
// [1,1,2,2,3,4]
// ✅ Interpretation:

// Amount 0: 1 way

// Amount 1: 1 way

// Amount 2: 2 ways

// Amount 3: 2 ways

// Amount 4: 3 ways

// Amount 5: 4 ways

// ✅ Total ways to make amount 5 using {1,2,5}:

// 1+1+1+1+1

// 1+1+1+2

// 1+2+2

// 5

// Complexity
// Time: O(amount × #coins) = O(5×3)

// Space: O(amount) = O(5)

