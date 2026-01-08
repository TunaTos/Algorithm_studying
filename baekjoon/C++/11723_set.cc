#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define endl '\n'
using namespace std;

set<int> s;
string command;
int n;

void do_case() {
    int num;

    cin >> command;

    if (command == "empty")
    {
        s.clear();
        return ;
    }
    else if (command == "all")
    {
        for (int i = 1; i <= 20; ++i)
            s.insert(i);
        return ;
    }
    cin >> num;
    if (command == "add")
        s.insert(num);
    
    else if (command == "remove")
    {
        s.extract(num);
    }
    else if (command == "check")
    {
        s.find(num) == s.end() ? cout << 0 << endl : cout << 1 << endl;
    }
    else if (command == "toggle")
    {
        if (s.find(num) != s.end())
            s.extract(num);
        else   
            s.insert(num);
    }
    
}

void show_set()
{
    for (const auto& ele: s)
        cout << ele << " ";
    cout << endl;
}

int main (void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    while (n--)
    {
        do_case();
        //show_set();
    }


    return(0);  
}