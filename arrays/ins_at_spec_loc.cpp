
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr={1,4,5,3,6};
    int x=2;
    int pos=3;
    int n =arr.size();
    for(int i=n-1;i>=pos;i--){
        arr[i+1]=arr[i];
    }
    arr[pos]=x;
    for(int i=0;i<n+1;i++){
        cout<<arr[i];
    }
    return 0;
}