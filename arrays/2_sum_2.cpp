#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    int i = 0;
    int j = n - 1;
    while (i < j) {
        if (numbers[i] + numbers[j] > target) {
            j--;
        }
        else if (numbers[i] + numbers[j] < target) {
            i++;
        }
        else {
            return {i + 1, j + 1}; // 1-indexed
        }
    }
    return {};
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(numbers, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No two numbers found.\n";
    }

    return 0;
}
