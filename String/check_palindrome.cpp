#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s="racecar";
    int i=0;
    int n=s.length();
    int j=n-1;
    int flag=0;
    while(i<j){
        if(s[i]!=s[j]){
            flag=0;
            break;
        }
        else{
            flag=1;
            i++;
            j--;
        }
    }
    if(flag){
        cout<<"pal";
    }
    else{
        cout<<"not pal";
    }

    return 0;
}