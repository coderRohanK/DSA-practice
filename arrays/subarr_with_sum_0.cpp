#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {4, 2, -3, 1, 6};
    unordered_map<int, int> m;
    int sum = 0;

    for(int i=0; i<nums.size(); i++){
        sum += nums[i];

        if(sum == 0){
            cout << "Subarray with 0 sum exists from 0 to " << i << endl;
            return 0;
        }

        if(m.find(sum) != m.end()){
            cout << "Subarray with 0 sum exists from " << m[sum]+1 << " to " << i << endl;
            return 0;
        }

        m[sum] = i;
    }

    cout << "No subarray with 0 sum" << endl;
    return 0;
}
