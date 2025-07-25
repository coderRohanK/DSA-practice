#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {2,1,5,3};
    int k=5;
    int n=v.size();
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        if(m.find(k-v[i])!=m.end()){
            cout<<m[k-v[i]]<<","<<i;
        }
        else{
            m[v[i]]=i;
        }
    }
    return 0;
}
