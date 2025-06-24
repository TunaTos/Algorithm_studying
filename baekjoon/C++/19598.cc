#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using pii = std::pair<int,int>;
using namespace std;

/**
 * N개의 회의를 모두 진행할 수 있는 최소 회의실 개수를 구하라
 * 한 회의실에ㅓ 동시에 두 개 이상의 회의가 진행될 수 없음
 * 회의는 한번 시작되면 중단돌 수 없음
 * 끝나는 것과 동시에 다음 회의가 시작될 수 있다 <ip>
 * 회의 시작 시간은 끝나는 시간보다 항상 작다.
 */

int N;
vector<pii> conferences; // 시작점, 끝점

void input()
{
    cin >> N;
    int start, end;
    for (int i = 0; i < N; i++)
    {
        cin >> start >> end;
        conferences.push_back(make_pair(start,end));
    }
    sort(conferences.begin(), conferences.end());
}

void getResult()
{
    int res = 1;
    int head = conferences[0].second;

    for (int i = 1; i < N; i++)
    {
        auto con = conferences[i];

        if (head <= con.first)
            head = con.second;
        else
        {
            ++res;
            head = con.second;
        }
    }
    
    cout << res;
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    getResult();

    return (0);
}