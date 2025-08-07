#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
//start
bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<string> seen;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char num = board[i][j];
            if (num == '.') continue;

            string rowKey = string(1, num) + " in row " + to_string(i);
            string colKey = string(1, num) + " in col " + to_string(j);
            string boxKey = string(1, num) + " in box " + to_string(i / 3) + "-" + to_string(j / 3);

            if (!seen.insert(rowKey).second || 
                !seen.insert(colKey).second || 
                !seen.insert(boxKey).second)
                return false;
        }
    }

    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << (isValidSudoku(board) ? "Valid Sudoku" : "Invalid Sudoku") << endl;

    return 0;
}
