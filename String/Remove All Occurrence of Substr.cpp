#include <iostream>
#include <string>
using namespace std;

string removeOccurrences(string s, string part) {
    string res = "";
    int plen = part.size();

    for(char c : s) {
        res += c;
        if(res.size() >= plen && res.substr(res.size()-plen, plen) == part) {
            res.erase(res.size()-plen, plen);
        }
    }
    return res;
}
