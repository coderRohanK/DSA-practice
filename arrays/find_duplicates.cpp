#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    unordered_map<int,int> m;

    for(int num : nums){
        m[num]++;
    }

    for(auto it : m){
        if(it.second > 1){
            res.push_back(it.first);
        }
    }

    return res;
}

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> duplicates = findDuplicates(nums);
    
    cout << "Duplicates: ";
    for(int num : duplicates){
        cout << num << " ";
    }
    return 0;
}
