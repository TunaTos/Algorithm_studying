#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#define endl '\n'
using namespace std;
unordered_map<string, int> m;

string solution(vector<string> participant, vector<string> completion) {
    
    for (string str: participant) {
        if (m.find(str) != m.end()) {
            m[str] = m[str] + 1;
        } else {
            m[str] = 1;
        }
    }
    
    for (string part: completion) {
        m[part] = m[part] - 1;
    }
    
    
    
    
    for (auto entry: m) {
        if (entry.second != 0)
            return entry.first;
    }
    
    return "";
}