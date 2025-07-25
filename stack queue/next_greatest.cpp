#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    vector<int> v;
    int n = nums2.size() - 1;

    s.push(nums2[n]);
    v.insert(v.begin(), -1);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && nums2[i] > s.top()) {
            s.pop();
        }
        if (s.empty()) {
            v.insert(v.begin(), -1);
        } else {
            v.insert(v.begin(), s.top());
        }
        s.push(nums2[i]);
    }

    unordered_map<int, int> m;
    for (int i = 0; i < nums2.size(); i++) {
        m[nums2[i]] = v[i];
    }

    vector<int> v1;
    for (int i = 0; i < nums1.size(); i++) {
        v1.push_back(m[nums1[i]]);
    }
    return v1;
}

int main() {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> result = nextGreaterElement(nums1, nums2);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
