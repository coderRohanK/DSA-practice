#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5]={6,2,4,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        int k=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>k){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=k;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}