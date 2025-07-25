// 1.i=0
// 2.j=n-1
// 3.calculate width (rp-lp)
// 4.calculate height (minimum of h[lp] and h[rp])
// 5.current capacity (width*height)
// 6.update max water (max(old and new))
// 7.move the smallest height pointer

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    int i=0;
    int n=v.size();
    int j=n-1;
    int maxi=0;
    while(i<j){
        int w=j-i;
        int mh=min(v[i],v[j]);
        int capacity=w*mh;
        maxi=max(maxi,capacity);
        if(v[i]<v[j]){
            i++;
        }
        else{
            j--;
        }
    }
    cout<<maxi;
    return 0;
}

