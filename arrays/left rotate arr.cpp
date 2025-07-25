#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    int n = nums.size();
    k = k % n;

    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.end());

    for(int num : nums){
        cout << num << " ";
    }
    return 0;
}
