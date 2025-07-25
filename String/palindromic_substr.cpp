#include <iostream>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            count += countPalindromes(s, i, i);
            count += countPalindromes(s, i, i + 1);
        }
        return count;
    }

private:
    int countPalindromes(string s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    cout << sol.countSubstrings("aaa") << endl; // Output: 6
    cout << sol.countSubstrings("abc") << endl; // Output: 3
    return 0;
}
