#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i=0;i<nums.size();i++){
        q.push(nums[i]);
        if(q.size() > k){
            q.pop();
        }
    }

    cout << q.top();
    return 0;
}
