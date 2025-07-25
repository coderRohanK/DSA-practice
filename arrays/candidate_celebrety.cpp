#include <iostream>
#include <vector>
using namespace std;

int celebrity(vector<vector<int>>& mat, int n) {
    int c = 0; // Assume first person as celebrity

    // Step 1: Find potential celebrity
    for (int i = 1; i < n; i++) {
        if (mat[c][i] == 1) {
            // c knows i -> c cannot be celebrity, i may be
            c = i;
        }
        // else i cannot be celebrity, c remains
    }

    // Step 2: Verify candidate
    for (int i = 0; i < n; i++) {
        if (i != c) {
            if (mat[c][i] == 1 || mat[i][c] == 0) {
                return -1;
            }
        }
    }

    return c;
}

int main() {
    vector<vector<int>> mat = {
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };
    int n = mat.size();
    cout << celebrity(mat, n) << endl; // Output: 1
    return 0;
}
