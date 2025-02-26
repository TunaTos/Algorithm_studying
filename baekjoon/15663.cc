#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> selected;
vector<bool> used;

void dfs(int depth) {
    if (depth == M) {
        for (int num : selected) cout << num << " ";
        cout << "\n";
        return;
    }

    int prev = -1;
    for (int i = 0; i < N; i++) {
        if (!used[i] && numbers[i] != prev) {
            used[i] = true;
            selected.push_back(numbers[i]);
            prev = numbers[i];
            dfs(depth + 1);
            used[i] = false;
            selected.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    numbers.resize(N);
    used.resize(N, false);

    for (int i = 0; i < N; i++) cin >> numbers[i];

    sort(numbers.begin(), numbers.end());
    dfs(0);

    return 0;
}
