#include <bits/stdc++.h>
using namespace std;

int main() {
    string s="aabbccaa";
    unordered_map<char,int> m;
    int n=s.length();
    for(int i=0;i<n;i++){
        m[s[i]]++;
    }
    for(auto it:m){
        cout<<it.second<<it.first;
    }
    return 0;
}
// O(n) time

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s="aabbccaa";
    map<char,int> m;
    int n=s.length();
    for(int i=0;i<n;i++){
        m[s[i]]++;
    }
    for(auto it:m){
        cout<<it.second<<it.first;
    }
    return 0;
}
// O(n log k) time

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "aabbccaa";
    int counts[26] = {0};
    for(char c : s) {
        counts[c - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(counts[i] > 0)
            cout << counts[i] << (char)(i + 'a');
    }
    return 0;
}
// O(26) time