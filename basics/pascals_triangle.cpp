#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=5;
    for(int i=0;i<n;i++){
        int val=1;
        for(int j=0;j<n-1-i;j++){
            cout<<" ";
        }
        for(int j=0;j<=1;j++){
            cout<<val<<" ";
            val=val*(i-j)/(j+1);// formula
        }
        cout<<endl;
    }
    return 0;
}