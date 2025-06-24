#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef struct fri
{
    int root;
    int price;
};
fri arr[10001];
int Tcase, budget, Len;
int table[10001];
bool visited[10001];
void Debug()
{
    for (int i = 1; i <= Len; i++)
        cout << arr[i].root << " " << arr[i].price << '\n';
}
void Debug2()
{
    for (int i = 1; i <= Len; i++)
        cout << table[i] << endl;
}
void Init()
{
    cin >> Len >> Tcase >> budget;
    int input;
    for (int i = 1; i <= Len; i++)
    {
        cin >> input;
        arr[i].root = i;
        arr[i].price = input;
    }
}

int Find(int x)
{
    if (arr[x].root == x) return x;
    else
        return arr[x].root = Find(arr[x].root);
}

void Merge(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b)
        return;

    // 작은 쪽의 루트로 합침
    if (arr[a].price <= arr[b].price)
        arr[b].root = a;
    else
        arr[a].root = b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;

    Init();
    for (int i = 0; i < Tcase; i++)
    {
        cin >> a >> b;
        Merge(a, b);
       // Debug(); cout << endl;
    }

    for (int i = 1; i <= Len; i++)
    {
        int root = Find(i);
        if (table[root] == 0)
            table[root] = arr[i].price;
        else
            table[root] = min(table[root], arr[i].price);
    }
    //Debug();
    //cout << endl << endl;

    //Debug2();

    int tmp = 0;

    for (int i = 1; i <= Len; i++)
    {
        tmp += table[i];

        if (tmp > budget)
        {
            cout << "Oh no";
            return 0;
        }
    }

    cout << tmp;

    return 0;
}