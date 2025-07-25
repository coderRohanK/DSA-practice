#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    if(s.size() % 2 != 0) return false;
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if(st.empty()) return false;
            if((st.top() == '(' && s[i] != ')') || 
               (st.top() == '{' && s[i] != '}') || 
               (st.top() == '[' && s[i] != ']')) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s = "{[()]}";
    if(isValid(s))
        cout << "Valid" << endl;
    else
        cout << "Invalid" << endl;
    return 0;
}
