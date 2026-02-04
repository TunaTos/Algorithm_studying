#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#define endl '\n'
using namespace std;

unordered_set<string> d_set, b_set;
int d_size, b_size;
vector<string> db;

void show_set(unordered_set<string> set) {
    for (string name: set) 
        cout << name << " ";
    cout << endl;
}

void input() {
    cin >> d_size >> b_size;
    string name;
    
    for (int i = 0; i < d_size; ++i) {
        cin >> name;
        d_set.insert(name);    
    }


    for (size_t i = 0; i < b_size; i++)
    {
        cin >> name;
        b_set.insert(name);
    }
}

void solve() {
    for (string d_name: d_set) {
        if (b_set.find(d_name) != b_set.end()) {
            db.push_back(d_name);
        }
    }

    
    sort(db.begin(), db.end(), [](const string& a,const string& b)  {
        return a < b;
    });

    cout << db.size() << endl;
    for (string db_name: db) {
        cout << db_name << endl;
    }
}



int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    //show_set(d_set);
    solve();
    return (0);
}