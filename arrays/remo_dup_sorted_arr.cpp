
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[6]={1,2,5,5,6,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int j=0;
    for(int i=1;i<n;i++){
        if(arr[i] != arr[j]){
            j++;
            arr[j] = arr[i];
        }
    }
    for(int i=0;i<=j;i++){
        cout<<arr[i];
    }
    return 0;
}