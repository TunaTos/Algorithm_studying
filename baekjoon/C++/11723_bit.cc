#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#define endl '\n'
using namespace std;

bitset<20> b_set;
string command;
int N;


void do_case()
{
    cin >> command;
    int num;
    if (command == "all") {
        b_set.set();
        return ;
    }
    else if (command == "empty")
    {
        b_set.reset();
        return ;
    }
    cin >> num;
    if (command == "add")
        b_set[num-1] = true;
    else if (command == "remove")
        b_set[num-1] = false;
    else if (command == "check")
        b_set[num-1] == true ? cout << 1 << endl : cout << 0 << endl;
    else if (command == "toggle")
        b_set ^= pow(2, num-1);
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    while (N--) 
    {
        do_case();
        //cout << b_set.to_string() << endl;
    }

    return (0);
}