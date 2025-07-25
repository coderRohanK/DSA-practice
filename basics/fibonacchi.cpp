// #include <bits/stdc++.h>
// using namespace std;

// int fib(int n){
//     if(n<=1) return n;
//     return fib(n-1) + fib(n-2);
// }
// int main() {
//     int n = 5;
//     cout << fib(n);
//     return 0;
// }
// above code not optimal

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    int a = 0, b = 1, c;
    if(n == 0) cout << a;
    else if(n == 1) cout << b;
    else {
        for(int i=2; i<=n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        cout << b;
    }
    return 0;
}
//O(n) time
//O(1) space