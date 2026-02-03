#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;
int idx1 = 0, idx2 = 9, res;

void debug() {
    for (pair<string, int> p : m) {
        cout << p.first << " " << p.second << endl;
    }
}

void check_result(const vector<string>& want, const vector<int>& number) {
    for (int i = 0; i < want.size(); ++i) 
        if ((m.find(want[i]) == m.end()) || (m[want[i]] != number[i]))
            return ;
    ++res;
}



int solution(vector<string> want, vector<int> number, vector<string> discount) {
    // 초기 설정
    for (int i = 0; i <= 9; ++i) {
        if (m.find(discount[i]) != m.end()) {
            m[discount[i]] += 1;
        } else {
            m[discount[i]] = 1;
        }
    }
    
    debug();
    
    while (true) {
        check_result(want, number);
        
        m[discount[idx1]]--;
        ++idx1;
        
        if (idx2 == discount.size() - 1) {
            return res;
        } else {
            ++idx2;
            if (m.find(discount[idx2]) != m.end()) {
                m[discount[idx2]] = m[discount[idx2]] + 1;
            } else {
                m[discount[idx2]] = 1;
            }
        }
    }    
}

