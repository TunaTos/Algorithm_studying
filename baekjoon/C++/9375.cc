#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#define endl '\n'
using namespace std;

int tcase, n, res;
unordered_map<string,unordered_set<string>> clothes;


void show_clothes() {
    for (const auto& tmp: clothes)
    {
        cout << tmp.first << " : ";
        for (const auto& s: tmp.second)
            cout << s << " ";
        cout << endl;
    }
}


void input() {
    cin >> n;
    string key, val;

    for (int i = 0; i < n; ++i) {
        cin >> val >> key;
        clothes[key].insert(val);
    }
}

void get_result() {
    res = 1;
    for (const auto& node: clothes)
        res *= (node.second.size() + 1);
    
    res -= 1;

    cout << res << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> tcase;

    while (tcase--) {
        input();
        //show_clothes();
        get_result();
        clothes.clear();
        res = 0;
    }

    return (0);
}