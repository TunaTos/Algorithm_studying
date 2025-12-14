#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using pii = pair<int, int>;

int N;
vector<pii> conferences;

void input() {
    cin >> N;
    int start, end;
    for (int i = 0; i < N; i++) {
        cin >> start >> end;
        conferences.emplace_back(start, end);
    }
    sort(conferences.begin(), conferences.end()); 
}

void getResult() {
    priority_queue<int, vector<int>, greater<int>> pq; 
    
    pq.push(conferences[0].second); 
    for (int i = 1; i < N; i++) {
        int start = conferences[i].first;
        int end = conferences[i].second;
        
        if (pq.top() <= start) {
            pq.pop(); 
        }
        
        pq.push(end); 
    }

    cout << pq.size(); 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    getResult();

    return 0;
}