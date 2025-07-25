#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5; 
    long long val = 1;
    for(int k = 0; k < n; k++){
        cout << val << " ";
        val = val * (n - 1 - k) / (k + 1);
    }
    return 0;
}
