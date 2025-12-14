#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> eggs; // {내구도, 무게}
int max_broken = 0;

void dfs(int idx) {
    if (idx == N) { // 모든 계란을 다 들었을 경우
        int broken_count = 0;
        for (auto &egg : eggs)
            if (egg.first <= 0) broken_count++;
        max_broken = max(max_broken, broken_count);
        return;
    }

    if (eggs[idx].first <= 0) { // 현재 계란이 깨져 있으면 다음 계란으로 이동
        dfs(idx + 1);
        return;
    }

    bool any_hit = false;
    for (int i = 0; i < N; i++) {
        if (i == idx || eggs[i].first <= 0) continue; // 자기 자신 또는 깨진 계란 제외

        any_hit = true;

        // 충돌 (내구도 감소)
        eggs[idx].first -= eggs[i].second;
        eggs[i].first -= eggs[idx].second;

        // 다음 계란으로 진행
        dfs(idx + 1);

        // 원상 복구 (백트래킹)
        eggs[idx].first += eggs[i].second;
        eggs[i].first += eggs[idx].second;
    }

    // 깨지지 않은 계란이 없거나, 들고 있는 계란이 유일한 남은 계란일 경우
    if (!any_hit) dfs(idx + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    eggs.resize(N);
    for (int i = 0; i < N; i++)
        cin >> eggs[i].first >> eggs[i].second;

    dfs(0);
    cout << max_broken << '\n';
    
    return 0;
}