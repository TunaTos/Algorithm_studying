#include <bits/stdc++.h>
using namespace std;

void solve() 
{
    long long start, end;
    cin >> start >> end;

    vector<bool> is_square_free(end - start + 1, true); 

    for (long long i = 2; i * i <= end; i++) {
        long long square = i * i;
        long long first_multiple = (start + square - 1) / square * square; 

        for (long long j = first_multiple; j <= end; j += square) 
		{
            is_square_free[j - start] = false;
        }
    }

    long long count = 0;
    for (bool free : is_square_free) 
	{
        if (free) count++;
    }
    
    cout << count << '\n';
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
