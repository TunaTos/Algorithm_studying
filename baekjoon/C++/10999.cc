#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

vector<ll> segTree;
ll N, M, K, H, treeSize; // 원소의 개수, 수의 변경이 일어나는 횟수, 구간의 합을 구하는 횟수


template<typename T>
void showSegTree(const T& tree)
{
	for (ll i =1; i < treeSize; ++i)
		cout << tree[i] << " ";
	cout << endl;
}

void input()
{
	cin >> N >> M >> K;
	H = ceil(log2(N));

	treeSize = 1LL << (H+1);
	segTree.assign(treeSize, 0);
}

void buildTree()
{
	ll number;
	for (int i = 0; i < N; ++i)
	{
		cin >> number;
		segTree[treeSize/2 + i] = number;
	}
	
	for (int i = treeSize - 1; i >= 1; --i)
		segTree[i/2] += segTree[i];
	
}

void updateNode(int idx, int node)
{
	idx = treeSize/2 + idx - 1;
	ll dis = node - segTree[idx];
	segTree[idx] = node;

	for (int i = idx; i > 1; i /= 2)
		segTree[i/2] += dis;
}

ll getSum(int left, int right)
{
	// left에서 right까지의 합을 구하라
	left = treeSize / 2 + left - 1;
	right = treeSize / 2 + right - 1;


	ll sum = 0;

	while (left <= right)
	{
		if (left % 2 == 1) sum += segTree[left++];
		if (right % 2 == 0) sum += segTree[right--];
		left /= 2;
		right /= 2;
	}
	return sum;
}


void solve()
{
	input();
	buildTree();
	//showSegTree(segTree);
	int flag, num1, num2;
	for (int i = 0; i < M + K; i++)
	{
		cin >> flag >> num1 >> num2;
		if (flag == 1)
			updateNode(num1, num2);
		else
			cout << getSum(num1, num2) << endl;
		//showSegTree(segTree);
	}
	
}



signed main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	solve();



	return (0);
}