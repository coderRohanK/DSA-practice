#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[9]={1,2,0,5,5,0,0,6,9};
    int count=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    int j=0;
    for(int i=1;i<n;i++){
        if(arr[i]!=0){
            j++;
            arr[j]=arr[i];
        }
        else{
            count++;
        }
    }
    while(count>0){
        arr[n-count]=0;
        count--;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}