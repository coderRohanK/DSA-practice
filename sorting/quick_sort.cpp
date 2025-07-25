#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[j] > pivot && j > low){
            j--;
        }
        while(arr[i] <= pivot && i < high){
            i++;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high){
    if(low < high){
        int par = partition(arr, low, high);
        quicksort(arr, low, par - 1);
        quicksort(arr, par + 1, high);
    }
}

int main() {
    int arr[5] = {6, 2, 4, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
