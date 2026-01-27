#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
using ll = long long;

int N, M, K, base = 1; // 수의 개수, 변경의 수, 구간합 구하는 수
vector<ll> tree;

void show_tree() {
    for (int i = 1; i < tree.size(); ++i)
        cout << tree[i] << " ";
    cout << endl;
}

void input() 
{
    cin >> N >> M >> K;
    while (base < N)
        base <<= 1;
    
    tree.assign(base * 2 , 0);
    
    for (int i = 0; i < N; ++i) 
        cin >> tree[base + i];
}

void build_tree() {
    for (int i = base -1; i >= 1; --i) 
        tree[i] = tree[i * 2] + tree[i * 2 + 1];   
}

ll get_sum(int left, int right) 
{
    ll res = 0;
    
    left = left + base - 1;
    right = right + base - 1;

    while (left <= right) {
        if (left == right) {
            res += tree[left];
            break;
        }
        
        if (left & 1) res += tree[left++];
        if (!(right & 1)) res += tree[right--];
        left >>= 1; 
        right >>= 1;
    }

    return res;
}

void update(int idx, ll val) {
    idx = base + idx - 1;
    
    ll dis = val - tree[idx];

    while (idx >= 1) {
        tree[idx] += dis;
        idx >>= 1;    
    }
}


void solve() {
    ll num1, num2, flag;

    for (int i = 0; i < M + K; ++i) {
        cin >> flag >> num1 >> num2;
        
        if (flag == 2)
            cout << get_sum(num1, num2) << endl;
        else
            update(num1, num2);
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    input();   
    build_tree();
    //show_tree();
    solve();

    return (0);
}