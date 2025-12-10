/**
 * 기관총 앞쪽 길의 거리는 L이다
 * 진지로 부터 i 떨어진 곳은 Z이다.
 * 
 * 
 * 1m 이동할 떄 기관총 or 지뢰
 * 
 * [기관총]
 * 유효 사거리는 M이다. Mk만큼 낮춘다.
 * 
 * [지뢰]
 * 유효 사거리는 1이다.
 * 진지 앞 1m의 좀비는 제압할 수 있음
 * 
 * C개 있음
 * 
 * 
 * 살아남을 수 있는가 없는가를 출력하라
 */

#include <bits/stdc++.h>
#define endl '\n'
using ull = long long;
using namespace std;

ull L, M, K, C; // 거리, 사거리, 살상력, 지뢰
vector<ull> zombies;

void input()
{
	cin >> L >> M >> K >> C;
	zombies.assign(L+1, 0);

	for (int i = 1; i <= L; i++)
		cin >> zombies[i];
}

void solve() {
	/**
	 * greedy 방식 -> 기관총으로 죽일 수 없으면 폭탄으로 죽여라
	 * 
	 * 핵심: 지뢰를 사용하면 그 턴에 기관총을 못 쏨
	 * -> 지뢰 사용 위치를 추적해서 기관총 사격 횟수를 줄여야 함
	 */

	queue<ull> mine_used; // 지뢰 사용한 위치 저장

	for (ull i = 1; i <= L; i++)
	{
		// M 범위를 벗어난 지뢰는 더 이상 영향을 주지 않음
		while (!mine_used.empty() && mine_used.front() < i - M + 1) {
			mine_used.pop();
		}

		// 실제 기관총 사격 횟수 = min(i, M) - 지뢰 사용 횟수
		ull gun_shots = min(i, M) - mine_used.size();
		ull damage = K * gun_shots;
		
		// 죽일 수 없는 case
		if (zombies[i] > damage) {
			if (C == 0) {
				cout << "NO" << endl;
				return ;
			}
			--C;
			mine_used.push(i); // 지뢰 사용 위치 기록
		}
	}
	cout << "YES" << endl;
}

int main(void)
{	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	input();
	solve();

	return(0);
}