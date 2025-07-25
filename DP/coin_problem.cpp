#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins,int amount) {
    vector<int> dp(amount+1,INT_MAX);
    dp[0] = 0;
    for(int i=1;i<=amount;i++) {
        for(int coin:coins) {
            if(i-coin>=0 && dp[i-coin]!=INT_MAX)
                dp[i]=min(dp[i],dp[i-coin]+1);
        }
    }
    return dp[amount]==INT_MAX?-1:dp[amount];
}

int main(){
    vector<int> coins={1,2,5};
    int amount=11;
    cout<<coinChange(coins, amount);
    return 0;
}

// Initialization
// dp[0] = 0
// → To make amount 0, 0 coins needed.

// All other dp[i] = INT_MAX initially (meaning not reachable yet).

// Iteration over i = 1 to amount (11)
// ✅ i=1:

// coin=1:

// i-coin = 0

// dp[0]=0, so dp[1]=min(INT_MAX,0+1)=1

// coin=2: i-coin < 0 (skip)

// coin=5: i-coin < 0 (skip)

// ➡️ dp[1]=1

// ✅ i=2:

// coin=1:

// i-coin=1, dp[1]=1

// dp[2]=min(INT_MAX,1+1)=2

// coin=2:

// i-coin=0, dp[0]=0

// dp[2]=min(2,0+1)=1

// coin=5: i-coin < 0 (skip)

// ➡️ dp[2]=1

// ✅ i=3:

// coin=1:

// i-coin=2, dp[2]=1

// dp[3]=min(INT_MAX,1+1)=2

// coin=2:

// i-coin=1, dp[1]=1

// dp[3]=min(2,1+1)=2

// coin=5: i-coin < 0 (skip)

// ➡️ dp[3]=2

// ✅ i=4:

// coin=1:

// i-coin=3, dp[3]=2

// dp[4]=min(INT_MAX,2+1)=3

// coin=2:

// i-coin=2, dp[2]=1

// dp[4]=min(3,1+1)=2

// coin=5: i-coin < 0 (skip)

// ➡️ dp[4]=2

// ✅ i=5:

// coin=1:

// i-coin=4, dp[4]=2

// dp[5]=min(INT_MAX,2+1)=3

// coin=2:

// i-coin=3, dp[3]=2

// dp[5]=min(3,2+1)=3

// coin=5:

// i-coin=0, dp[0]=0

// dp[5]=min(3,0+1)=1

// ➡️ dp[5]=1

// ✅ i=6:

// coin=1:

// i-coin=5, dp[5]=1

// dp[6]=min(INT_MAX,1+1)=2

// coin=2:

// i-coin=4, dp[4]=2

// dp[6]=min(2,2+1)=2

// coin=5:

// i-coin=1, dp[1]=1

// dp[6]=min(2,1+1)=2

// ➡️ dp[6]=2

// ✅ i=7:

// coin=1:

// i-coin=6, dp[6]=2

// dp[7]=min(INT_MAX,2+1)=3

// coin=2:

// i-coin=5, dp[5]=1

// dp[7]=min(3,1+1)=2

// coin=5:

// i-coin=2, dp[2]=1

// dp[7]=min(2,1+1)=2

// ➡️ dp[7]=2

// ✅ i=8:

// coin=1:

// i-coin=7, dp[7]=2

// dp[8]=min(INT_MAX,2+1)=3

// coin=2:

// i-coin=6, dp[6]=2

// dp[8]=min(3,2+1)=3

// coin=5:

// i-coin=3, dp[3]=2

// dp[8]=min(3,2+1)=3

// ➡️ dp[8]=3

// ✅ i=9:

// coin=1:

// i-coin=8, dp[8]=3

// dp[9]=min(INT_MAX,3+1)=4

// coin=2:

// i-coin=7, dp[7]=2

// dp[9]=min(4,2+1)=3

// coin=5:

// i-coin=4, dp[4]=2

// dp[9]=min(3,2+1)=3

// ➡️ dp[9]=3

// ✅ i=10:

// coin=1:

// i-coin=9, dp[9]=3

// dp[10]=min(INT_MAX,3+1)=4

// coin=2:

// i-coin=8, dp[8]=3

// dp[10]=min(4,3+1)=4

// coin=5:

// i-coin=5, dp[5]=1

// dp[10]=min(4,1+1)=2

// ➡️ dp[10]=2

// ✅ i=11:

// coin=1:

// i-coin=10, dp[10]=2

// dp[11]=min(INT_MAX,2+1)=3

// coin=2:

// i-coin=9, dp[9]=3

// dp[11]=min(3,3+1)=3

// coin=5:

// i-coin=6, dp[6]=2

// dp[11]=min(3,2+1)=3

// ➡️ dp[11]=3

// Final Result
// ✅ To make amount = 11, minimum coins needed = dp[11] = 3
// (using coins like 5+5+1 or other combinations)