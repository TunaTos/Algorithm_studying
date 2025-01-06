#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() 
{
    ll A, B;
    cin >> A >> B;
    
    const ll limit = 1e7;
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (ll i = 2; i * i <= limit; i++) 
	{
        if (is_prime[i]) 
		{
            for (ll j = i * i; j <= limit; j += i) 
                is_prime[j] = false;
        }
    }

    ll count = 0;
    for (ll i = 2; i <= limit; i++) 
	{
        if (is_prime[i]) 
		{
            for (ll power = i * i; power <= B; power *= i) 
			{
                if (power >= A) 
                    count++;
                if (power > B / i) 
					break;
            }
        }
    }
    cout << count << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
