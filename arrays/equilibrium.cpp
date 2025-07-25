// prefix[i]==suffix[i]

#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v={1,2,0,3};
    vector<int> n(v.size());
    vector<int> s(v.size());
    s[v.size()-1]=v[v.size()-1];
    n[0]=v[0];
    for(int i=1;i<v.size();i++){
        n[i]=n[i-1]+v[i];
    }
    for(int i=v.size()-1;i>=0;i--){
        s[i]=s[i+1]+v[i];
    }
    for(int i=0;i<v.size();i++){
        cout<<n[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<v.size();i++){
        if(n[i]==s[i]){
            cout<<i<<" eqi";
        }
    }
    return 0;
}