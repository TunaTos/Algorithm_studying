#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_VERT 1001

using namespace std;

class Edge
{
public:
    int start;
    int end;
    int weight;

    Edge(int input1, int input2, int input3) : start(input1), end(input2), weight(input3)
    {}

    bool operator < (const Edge& e) const { return this->weight > e.weight; }
};

int parents[MAX_VERT], weight[MAX_VERT];
int V, E, Case;
vector<Edge> vec;

// Function For Union Find
int Find(int a) 
{
    if (parents[a] == a) return a;
    else
        return parents[a] = Find(parents[a]);
}

void Union(int a, int b) 
{
    a = Find(a);
    b = Find(b);

    if (a == b) return;

    if (weight[a] > weight[b])
    {
        parents[b] = parents[a];
        weight[a] += weight[b];
    }
    else
    {
        parents[a] = parents[b];
        weight[b] += weight[a];
    }
}

void Init() noexcept
{
    for (int i = 1; i <= V; i++)
    {
        parents[i] = i;
        weight[i] = 1;
    }
}

void Input() noexcept
{
    int a, b, c;

    cin >> V >> E >> Case;

    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;
        vec.emplace_back(a, b, c);
    }

    sort(vec.begin(), vec.end());
}

// Solve
int Solve(int input1, int input2) noexcept
{
    for (const auto& edge : vec)
    {
        int a = edge.start;
        int b = edge.end;
        int c = edge.weight;

        if (Find(a) != Find(b))
        {
            Union(a, b);
            if (Find(input1) == Find(input2))
                return c;
        }
    }

    return -1; // To handle cases where no result is found
}

// Function For Debug
void show_vec()
{
    cout << "This is vec" << endl;
    for (const auto& ele : vec)
        cout << ele.start << " " << ele.end << " " << ele.weight << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Input();
    int input1, input2;
    //show_vec();

    for (int i = 0; i < Case; i++)
    {
        Init();
        cin >> input1 >> input2;
        cout << Solve(input1, input2) << '\n';
    }
}
