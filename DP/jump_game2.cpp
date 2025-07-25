#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {2,4,1,2,3,1,1,2};
    int n = nums.size();
    int jumps = 0;
    int pos = n - 1;
    while(pos > 0){
        for(int i = 0; i < pos; i++){
            if(i + nums[i] >= pos){
                pos = i;
                jumps++;
                break;
            }
        }
    }
    cout << jumps << endl;
    return 0;
}


// 
// 
// 


#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {2,3,1,1,4};
    int n = nums.size();
    int jumps = 0, currEnd = 0, farthest = 0;

    for(int i = 0; i < n - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        if(i == currEnd) {
            jumps++;
            currEnd = farthest;
        }
    }

    cout << jumps << endl;
    return 0;
}

