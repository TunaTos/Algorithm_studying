#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#define endl '\n'
using namespace std;

set<string> mySet;
int N, M;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    cin >> N >> M;
    string input;

    int res{0};
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        mySet.insert(input);    
    }
    for (int i = 0; i <M; ++i)
    {
        cin >> input;
        if (mySet.find(input) != mySet.end())
            ++res;
    }
    cout << res;
    
    return (0);
}