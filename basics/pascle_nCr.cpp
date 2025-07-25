#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r){
    if(r > n - r)
        r = n - r;
    long long res = 1;
    for(int i = 0; i < r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
int main() {
    int n = 5, r = 2;
    cout << nCr(n, r);
    return 0;
}
