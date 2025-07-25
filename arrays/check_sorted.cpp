#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5]={1,2,5,6,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            cout<<"not sorted";
            return 0;
        }
    }
    cout<<"sorted";
    return 0;
}