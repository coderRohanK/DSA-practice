#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5]={3,5,2,8,1};
    int lar=INT_MIN;
    int seclar=INT_MIN;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>lar){
            seclar=lar;
            lar=arr[i];
        }
        else if(arr[i]>seclar && arr[i]!=lar){
            seclar = arr[i];
        }
    }
    cout<<seclar;
    return 0;
}
//O(n) time
//O(1) space