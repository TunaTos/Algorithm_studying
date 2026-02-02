#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

unordered_set<string> set;


bool solution(vector<string> phone_book) {
    
    for (string phone: phone_book) 
        set.insert(phone);
    
    for (string phone: phone_book) {
        for (int i = 0; i < phone.size(); ++i) {
            if (set.find(string(phone.begin(), phone.begin() + i)) != set.end())
                return false;
        }
    }
    
    return true;
}