#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    int n = s.size();
    int start = 0;
    for (int end = 0; end <= n; end++) {
        if (end == n || s[end] == ' ') {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
    }
}
int main() {
    string s = "hello world cpp";
    reverseWords(s);
    cout << s << endl;
    return 0;
}
