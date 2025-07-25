// 1.add first k element
// 2.subtract first element and add last element for next sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v={3,2,7,5,9,6,2};
    int n=v.size();
    int k=3;
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=v[i];
    }
    int maxsum=sum;
    for(int i=k;i<n;i++){
        sum+=v[i]-v[i-k];
        maxsum=max(sum,maxsum);
    }
    cout<<maxsum;
    return 0;
}
