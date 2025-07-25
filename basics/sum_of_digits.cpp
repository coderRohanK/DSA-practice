#include <bits/stdc++.h>
using namespace std;

int main() {
    int a=1234;
    int sums=0;
    while(a>0){
        sums+=a%10;
        a/=10;
    }
    cout<<sums;
    return 0;
}

// O(log₁₀ n) time, O(1) space