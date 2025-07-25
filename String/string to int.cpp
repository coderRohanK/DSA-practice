#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ')
            i++;
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (result * sign <= INT_MIN) return INT_MIN;
            if (result * sign >= INT_MAX) return INT_MAX;
            i++;
        }

        return result * sign;
    }
};

int main() {
    Solution sol;
    cout << sol.myAtoi("   -42") << endl;
    cout << sol.myAtoi("4193 with words") << endl;
    cout << sol.myAtoi("words and 987") << endl;
    cout << sol.myAtoi("-91283472332") << endl;   
}
