#include <bits/stdc++.h>
using namespace std;

int Tcase, F;
unordered_map<string,string> parents;
unordered_map<string,int> weights;

template<typename Map>
void showMap(const Map& M)
{
    for(const auto& ele: M)
        cout << "I am Key : " << ele.first << " " << "I am Value : " << ele.second;
}

string Find(const string& str) noexcept
{
    if(parents[str] == str) return str;
    else
        return parents[str] = Find(parents[str]);
}

void Union(string s1, string s2) noexcept
{
    auto key1 = Find(s1);
    auto key2 = Find(s2);    
    
    if(key1 == key2) return;

    else if(weights[key1] >= weights[key2])
    {
        weights[key1] += weights[key2];
        parents[key2] = key1;
    }
    else
    {
        weights[key2] += weights[key1];
        parents[key1] = key2;
    }
}

void reset() noexcept
{
    parents.clear();
    weights.clear();
}

int showWeight(string s1, string s2) noexcept
{
    int w1 = weights[Find(s1)];
    int w2 = weights[Find(s2)];

    if(w1 >= w2) return w1;
    else
        return w2;
}

void insertParentAndWeight(const string& str) noexcept
{
    if(parents.find(str) == parents.end()) // 없는 경우
    {
        parents[str] = str;
        weights[str] = 1;
    }
    else 
        return;
}

void solve() noexcept
{
    string s1, s2;

    cin >> F;
    for (int i = 0; i < F; i++)
    {
        cin >> s1 >> s2;
        insertParentAndWeight(s1);
        insertParentAndWeight(s2);

        Union(s1, s2);
        //showMap(parents);
        cout << showWeight(s1,s2) << endl;
    }
    reset();
}

int main(void)
{
    //ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> Tcase;

    for (int i = 0; i < Tcase; i++)
        solve();
    
    return (0);

}