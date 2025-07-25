#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1 = "hello";
    string s2 = "ll";
    
    for (int i = 0; i <= s1.size() - s2.size(); i++) {
        int j = 0;
        while (j < s2.size() && s1[i + j] == s2[j]) {
            j++;
        }
        if (j == s2.size()) {
            cout << "Substring found at index " << i << endl;
            return 0;
        }
    }
    cout << "Substring not found" << endl;
    return 0;
}
