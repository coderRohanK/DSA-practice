#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to encode a list of strings to a single string
string encode(vector<string>& strs) {
    string encoded;
    for (const string& s : strs) {
        encoded += to_string(s.size()) + '#' + s;
    }
    return encoded;
}

// Function to decode a single string back to a list of strings
vector<string> decode(string s) {
    vector<string> result;
    int i = 0;
    while (i < s.size()) {
        int j = i;
        while (s[j] != '#') j++;
        int len = stoi(s.substr(i, j - i));
        result.push_back(s.substr(j + 1, len));
        i = j + 1 + len;
    }
    return result;
}

int main() {
    vector<string> input = {"hello", "world", "#cpp", "123"};
    string encoded = encode(input);
    cout << "Encoded: " << encoded << endl;

    vector<string> decoded = decode(encoded);
    cout << "Decoded:" << endl;
    for (const string& s : decoded) {
        cout << s << endl;
    }

    return 0;
}
