#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define endl '\n'
using namespace std;

int N, R;
vector<int> numbers;
vector<int> tmp;


void makeCombination(int idx, int dpt) 
{
    if (dpt == R)
    {
        if (!is_sorted(tmp.begin(), tmp.end()))
            return;
        for (const auto& ele: tmp)
            cout << ele << " ";
        cout << endl;
        
        return ;
    }

    for (int i = 1; i <= N; ++i)
    {
        tmp.push_back(numbers[i]);
        makeCombination(i, dpt+1);
        tmp.pop_back();
    }


}

int main(void)
{
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> N >> R;
    numbers.resize(N+1, 0);
    iota(numbers.begin(), numbers.end(), 0);


    makeCombination(1,0);

    return (0);
}