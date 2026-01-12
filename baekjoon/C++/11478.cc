#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define endl '\n'
using namespace std;
using u_set = unordered_set<string>;

string str;
u_set s_set;


void solve()
{
    size_t str_len = str.length();

    for (auto i = str.begin(); i != str.end(); ++i) {
        for (auto j = i; j != str.end(); ++j) {
            s_set.insert(string(i,j + 1));        
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> str;
    solve();
    cout << s_set.size() << endl;


    return (0);
}