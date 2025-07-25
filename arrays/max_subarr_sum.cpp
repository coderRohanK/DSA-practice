#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int maxSum = nums[0];
    int currSum = nums[0];
    for(int i=1;i<nums.size();i++){
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }
    cout << "Maximum Subarray Sum: " << maxSum << endl;
    return 0;
}
