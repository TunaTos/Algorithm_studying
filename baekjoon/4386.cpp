#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX_LEN 101
using namespace std;

typedef struct pos
{
	double xpos;
	double ypos;
	int root;

	
	friend ostream& operator << (ostream& os,pos& e)
	{
		os << e.xpos << " " << e.ypos << " " << e.root;
		return os;
	}
}pos;


class Edge
{
public:
	pos p1;
	pos p2;
	double Len;

	Edge(pos input1, pos input2)
	{
		this->p1 = input1;
		this->p2 = input2;
		this->Len = sqrt(pow(input1.xpos - input2.xpos, 2) 
			+ pow(input1.ypos - input2.ypos, 2));
	}

	friend ostream& operator << (ostream& os, Edge& e) 
	{
		os << e.p1 << " " << e.p2 << " " << e.Len;
		return os;
	}

	bool operator < (Edge& e)
	{
		return this->Len < e.Len;
	}
};

int parents[MAX_LEN], weight[MAX_LEN];
int Len;
vector<pos> p_vec;
vector<Edge> e_vec;


/// <summary>
/// Functions
/// </summary>
void show_pos();
void show_edge();

//Function for Union-Find
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
	
	else if (weight[a] > weight[b])
	{
		weight[a] += weight[b];
		parents[b] = a;
	}
	else
	{
		weight[b] += weight[a];
		parents[a] = b;
	}
}




void Input()
{
	cin >> Len;
	double xpos, ypos;
	pos input;

	for (int i = 1; i <= Len; i++)
	{
		cin >> xpos >> ypos;
		input.xpos = xpos;
		input.ypos = ypos;
		input.root = i;
		p_vec.push_back(input);
	}
}

void set_edge()
{
	for (int i = 0; i < p_vec.size()-1; i++)
	{
		for (int j = i+1; j < p_vec.size(); j++)
		{
			e_vec.emplace_back(p_vec[i], p_vec[j]);
		}
	}
}

double Solve()
{
	double res = 0;

	for (int i = 0; i < e_vec.size(); i++)
	{
		Edge a = e_vec[i];
		
		if (Find(a.p1.root) != Find(a.p2.root)) // 다르다면
		{
			Union(a.p1.root, a.p2.root);
			res += a.Len;
		}
		else
			continue;
	}

	return res;



}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();

	for (int i = 1; i <= Len; i++)
	{
		weight[i] = 1;
		parents[i] = i;
	}

	set_edge();
	sort(e_vec.begin(), e_vec.end());

	cout << Solve();










	return 0;
}

void show_pos()
{
	cout << "This is pos" << endl;
	for (auto& ele : p_vec)
		cout << ele << endl;

}

void show_edge()
{
	cout << "This is edge" << endl;
	for (auto& ele : e_vec)
		cout << ele << endl;
}