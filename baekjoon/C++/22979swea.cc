#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;


/**
 * X > 0 -> 문자열의 길이로 나눈 뒤에 한다 (첫번째 때서 마지막에 붙음)
 * X < 0 -> // 마지막을 맨 앞에 붙임
 * X == 0 -> 아무것도 안한다
 */
int Tcase;


void runCase() 
{
    int X;
    string str;
    deque<char> dq;
    vector<int> instruction;
    
    cin >> str;
    for (size_t i = 0; i < str.length(); i++)
        dq.push_back(str[i]);


    cin >> X;
    for (int i = 0; i < X; i++)
    {
        int ins;
        cin >> ins;
        if (ins == 0)
            continue;
        if (ins < 0) // 음수
        {
            ins = ins * -1;
            ins = ins % str.length();
            
            for (int i = 0; i < ins; i++)
            {
                char c = dq.back();
                dq.pop_back();
                dq.push_front(c);
            }
            
        }
        else
        {
            ins = ins % str.length();
            for (int i = 0; i < ins; i++)
            {
                char c = dq.front();
                dq.pop_front();
                dq.push_back(c);    
            }
        }
    }


    for (const auto& ele : dq)
        cout << ele;
    cout << endl;
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    cin >> Tcase;

    for (size_t i = 0; i < Tcase; i++)
    {
        runCase();
    }
    return (0);
}
