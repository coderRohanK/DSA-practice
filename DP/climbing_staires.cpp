#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        vector<int> dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

// Iteration table for n=12
// We build dp[1] to dp[12].

// 🔢 Initialization
// ini
// Copy
// Edit
// dp = [0, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF]
// i=1
// j=1 → sq=1
// dp[1] = min(INF, 1 + dp[1-1]) = min(INF, 1 + 0) = 1

// ✅ dp = [0,1,INF,INF,...]

// i=2
// j=1 → sq=1
// dp[2] = min(INF, 1 + dp[2-1]) = min(INF, 1 + 1) = 2

// ✅ dp = [0,1,2,INF,...]

// i=3
// j=1 → sq=1
// dp[3] = min(INF, 1 + dp[3-1]) = min(INF, 1 + 2) = 3

// ✅ dp = [0,1,2,3,INF,...]

// i=4
// j=1 → sq=1
// dp[4] = min(INF, 1 + dp[4-1]) = min(INF, 1 + 3) = 4

// j=2 → sq=4
// dp[4] = min(4, 1 + dp[4-4]) = min(4, 1 + 0) = 1

// ✅ dp = [0,1,2,3,1,INF,...]

// i=5
// j=1 → sq=1
// dp[5] = min(INF, 1 + dp[5-1]) = min(INF, 1 + 1) = 2

// j=2 → sq=4
// dp[5] = min(2, 1 + dp[5-4]) = min(2, 1 + 1) = 2

// ✅ dp = [0,1,2,3,1,2,INF...]

// i=6
// j=1 → sq=1
// dp[6] = min(INF, 1 + dp[6-1]) = min(INF, 1 + 2) = 3

// j=2 → sq=4
// dp[6] = min(3, 1 + dp[6-4]) = min(3, 1 + 2) = 3

// ✅ dp = [0,1,2,3,1,2,3,INF...]

// i=7
// j=1 → sq=1
// dp[7] = min(INF, 1 + dp[7-1]) = min(INF, 1 + 3) = 4

// j=2 → sq=4
// dp[7] = min(4, 1 + dp[7-4]) = min(4, 1 + 3) = 4

// ✅ dp = [0,1,2,3,1,2,3,4,INF...]

// i=8
// j=1 → sq=1
// dp[8] = min(INF, 1 + dp[8-1]) = min(INF, 1 + 4) = 5

// j=2 → sq=4
// dp[8] = min(5, 1 + dp[8-4]) = min(5, 1 + 1) = 2

// ✅ dp = [0,1,2,3,1,2,3,4,2,INF...]

// i=9
// j=1 → sq=1
// dp[9] = min(INF, 1 + dp[9-1]) = min(INF, 1 + 2) = 3

// j=2 → sq=4
// dp[9] = min(3, 1 + dp[9-4]) = min(3, 1 + 2) = 3

// j=3 → sq=9
// dp[9] = min(3, 1 + dp[9-9]) = min(3, 1 + 0) = 1

// ✅ dp = [0,1,2,3,1,2,3,4,2,1,INF...]

// i=10
// j=1 → sq=1
// dp[10] = min(INF, 1 + dp[10-1]) = min(INF, 1 + 1) = 2

// j=2 → sq=4
// dp[10] = min(2, 1 + dp[10-4]) = min(2, 1 + 3) = 2

// j=3 → sq=9
// dp[10] = min(2, 1 + dp[10-9]) = min(2, 1 + 1) = 2

// ✅ dp = [0,1,2,3,1,2,3,4,2,1,2,INF...]

// i=11
// j=1 → sq=1
// dp[11] = min(INF, 1 + dp[11-1]) = min(INF, 1 + 2) = 3

// j=2 → sq=4
// dp[11] = min(3, 1 + dp[11-4]) = min(3, 1 + 4) = 3

// j=3 → sq=9
// dp[11] = min(3, 1 + dp[11-9]) = min(3, 1 + 2) = 3

// ✅ dp = [0,1,2,3,1,2,3,4,2,1,2,3,INF]

// i=12
// j=1 → sq=1
// dp[12] = min(INF, 1 + dp[12-1]) = min(INF, 1 + 3) = 4

// j=2 → sq=4
// dp[12] = min(4, 1 + dp[12-4]) = min(4, 1 + 2) = 3

// j=3 → sq=9
// dp[12] = min(3, 1 + dp[12-9]) = min(3, 1 + 3) = 3

// ✅ Final dp[12] = 3

// Answer
// ✔️ Minimum number of perfect squares to sum up to 12 is 3
// (4 + 4 + 4)