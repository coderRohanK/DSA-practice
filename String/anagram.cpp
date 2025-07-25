#include <bits/stdc++.h>
using namespace std;

int main() {
    string a="rat";
    string b="tar";
    int n=a.length();
    unordered_map<char,int> m;
    for(int i=0;i<n;i++){
        m[a[i]]++;
    }
    for(int i=0;i<n;i++){
        if(m[b[i]]==0){
            cout << "not anagram";
            return 0;
        }
        m[b[i]]--;
    }
    cout << "anagram";
    return 0;
}
// Time: O(n)
// Space: O(k)