#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "tacbc";
    int i = 0;
    int j = s.size() - 1;

    while (i < j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }

    cout << s;
    return 0;
}
