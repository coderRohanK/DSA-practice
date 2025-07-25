#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5] = {6, 2, 4, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n-1; i++){
        int min_idx = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
