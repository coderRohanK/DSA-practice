#include <iostream>
using namespace std;

bool isPalindrome(const string &s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    string s = "raceecar";
    cout << (isPalindrome(s) ? "true" : "false");
    return 0;
}


// ✅ Time Complexity
// O(n), where n is the length of the string.
// Each character is compared at most once (half the string).

// ✅ Space Complexity
// O(1) extra space.
// No additional data structures used; only pointers and constants.