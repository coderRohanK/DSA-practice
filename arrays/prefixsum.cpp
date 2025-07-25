// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v={1,2,0,3};
    vector<int> n(v.size());
    n[0]=v[0];
    for(int i=1;i<v.size();i++){
        n[i]=n[i-1]+v[i];
    }
    for(int i=0;i<v.size();i++){
        cout<<n[i]<<" ";
    }
    cout<<endl;
    int a=1;
    int b=3;
    int sum=n[b]-n[a-1];
    cout<<sum;
    return 0;
}