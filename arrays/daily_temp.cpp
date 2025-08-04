#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n, 0);
    stack<int> st; // stores indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int prev = st.top();
            st.pop();
            res[prev] = i - prev;
        }
        st.push(i);
    }
    return res;
}

int main() {
    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(temps);
    
    for (int days : result) {
        cout << days << " ";
    }
    cout << endl;

    return 0;
}
