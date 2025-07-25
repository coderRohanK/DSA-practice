#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp(n,false);
    dp[0]=true;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(dp[j] && j+nums[j]>=i){
                dp[i]=true;
                break;
            }
        }
    }
    return dp[n-1];
}
int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << canJump(nums);
    return 0;
}

// Example: nums = [2,3,1,1,4], length = 5
// dp[i] = can we reach index i?

// Initialize dp = [T, F, F, F, F].

// i	check all j < i with dp[j]=T and j+nums[j]≥i?	dp[i]
// 1	j=0: 0+2≥1 → yes	T
// 2	j=0: 0+2≥2 → yes	T
// 3	j=0: 0+2<3 → no; j=1: 1+3≥3 → yes	T
// 4	j=0:0+2<4; j=1:1+3≥4 → yes	T

// Final dp = [T,T,T,T,T].

// Answer: true (can reach last index)
// Time: O(n²) = O(25)
// Space: O(n) = O(5)

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums={2,3,1,0,4};
    int n=nums.size();
    int j=n-1;
    for(int i=n-2;i>=0;i--){
        if(i+nums[i]>=nums[j]){
            j--;
        }
    }
    if(j!=1){
        cout<<"flase";
    }
    else{
        cout<<"true";
    }
    return 0;
}