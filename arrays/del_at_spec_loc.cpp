#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5]={1,4,5,3,6};
    int pos=3;
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=pos;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}