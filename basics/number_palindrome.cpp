#include <bits/stdc++.h>
using namespace std;

int main() {
    int a=12321;
    int og=a;
    int b=0;
    while(a>0){
        b=b*10+(a%10);
        a=a/10;
    }
    if(og==b){
        cout<<"pal";
    }
    else{
        cout<<"not pal";
    }
    return 0;
}
//O(n) time
//O(1) space