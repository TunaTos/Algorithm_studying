#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solve {
public:
    vector<int> parents;
    vector<int> troops;

    Solve() = default;
    Solve(int N) : parents(N + 1), troops(N + 1) {
        for (int i = 1; i <= N; ++i)
            parents[i] = i;
    }

    void Init() {
        for (int i = 1; i < troops.size(); ++i)
            cin >> troops[i];
    }

    int Find(const int& a) {
        if (parents[a] == a) return a;
        return parents[a] = Find(parents[a]);
    }

    void Alliance(int &a, int& b) {
        a = Find(a);
        b = Find(b);
        if (a != b) { 
            parents[b] = a;
            troops[a] += troops[b];
            troops[b] = 0; 
        }
    }

    void Fight(int &a, int &b) {
        a = Find(a);
        b = Find(b);
        if (a != b) { 
            if (troops[a] == troops[b]) {
                troops[a] = troops[b] = 0;
            } else if (troops[a] > troops[b]) {
                parents[b] = a;
                troops[a] -= troops[b];
                troops[b] = 0; 
            } else {
                parents[a] = b;
                troops[b] -= troops[a];
                troops[a] = 0; 
            }
        }
    }

    void show_result() {
        vector<int> result;
        int remain_count = 0;
        for (int i = 1; i < troops.size(); ++i) 
        {
            if (parents[i] == i && troops[i] > 0) 
            {        
                remain_count++;
                result.push_back(troops[i]);
            }
        }
        sort(result.begin(), result.end());
        cout << remain_count << endl;
        for (const auto& t : result) {
            cout << t << " ";
        }
        cout << endl;
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M, a, b, c;
    cin >> N >> M;

    Solve solver(N);
    solver.Init();

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        if (a == 1)
            solver.Alliance(b, c);
        else
            solver.Fight(b, c);
    }

    solver.show_result();
    return 0;
}
