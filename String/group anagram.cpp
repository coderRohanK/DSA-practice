#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>> mp;
    vector<vector<string>> ans;
    for(string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        mp[key].push_back(s);
    }
    for(auto i : mp) {
        ans.push_back(i.second);
    }
    return ans;
}

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = groupAnagrams(strs);
    
    for(auto group : result) {
        for(string s : group) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
