#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5]={1,4,5,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        mini=min(arr[i],mini);
        maxi=max(arr[i],maxi);
    }
    cout<<mini;
    cout<<endl;
    cout<<maxi;
    return 0;
}