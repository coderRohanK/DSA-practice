#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "aabbccaa";
    unordered_map<char,int> m;
    vector<char> order;
    for(char c : s){
        if(m[c] == 0)
            order.push_back(c);
        m[c]++;
    }
    for(char c : order){
        cout << c;
    }
    return 0;
}

// O(n) time, O(k) space
