#include <iostream>
#include <vector>
#include <algorithm>  
#define endl '\n'
#define DIV 1000000007
using namespace std;
using ll = long long;

vector<ll> segTree;
int treeSize, H, N, M, K; // 수 변경되는 수, 쿼리의 수

void showTree()
{
    for (int i =1; i < treeSize; ++i)
        cout << segTree[i] << " ";
    cout << endl;
}

void input()
{
    cin >> N >> M >> K;

    H = ceil(log2(N));
    treeSize = 1 << (H + 1);    
    segTree.assign(treeSize, 0);
}

void buildTree()
{
    for (int i = 0; i < N; i++)
    {
        ll num;
        cin >> num;
        segTree[treeSize/2 + i] = num;
        segTree[treeSize/2 + i] %= DIV;
    }

    for (int i = treeSize / 2 - 1; i >= 1; i--)
    {
        //cout << "I am i : " << i << endl;
        ll leftChild = segTree[i * 2];
        ll rightChild = segTree[i * 2 + 1];
        //segTree[i] = leftChild * rightChild;
        segTree[i] = ((leftChild % DIV) * (rightChild % DIV) % DIV);
    }
    
    
}

void update(int idx, ll number)
{
    idx = treeSize / 2 + idx - 1;
    int parentIdx = idx / 2;

    segTree[idx] = number;

    for (int i = parentIdx; i >= 1; i = i / 2)
    {
        segTree[i] = (segTree[i * 2] % DIV *
            segTree[i * 2 + 1] % DIV) % DIV;
    }
}

void getMult(int left, int right)
{
    left = treeSize / 2 + left - 1;
    right = treeSize / 2 + right - 1;

    ll result = 1;

    while (left <= right)
    {
        if (left % 2 == 1) // right child인 경우
            result = (result % DIV * segTree[left++] % DIV);
        if (right % 2 == 0)
            result = (result % DIV * segTree[right--] % DIV);
        
        if (left == right)
            result = result % DIV * segTree[left] % DIV;
        left = left / 2;
        right = right / 2;


    }
    cout << result << endl;
}


void solve()
{
    input();
    buildTree();
    for (int i = 0; i < M + K; i++)
    {
        ll flag, left, right;
        cin >> flag >> left >> right;
        if (flag == 1)
            update(left, right);
        if (flag == 2)
            getMult(left, right);
        //showTree();
    }
    
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return (0);
}
