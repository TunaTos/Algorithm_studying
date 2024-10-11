#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define MAX_LEN 4000001
using namespace std;
int N, back =0, front =1, res;
bool isPrime[MAX_LEN];
vector<int> dp;

// Function For Debug
void show_prime();
void show_dp();


void setPrime()
{
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;

	int sqrtn = int(sqrt(N));

	for (int i = 2; i <= sqrtn; i++)
	{
		if (isPrime[i])
		{
			for (int j = i*i; j <= N; j+=i)
				isPrime[j] = false;
			
		}
	}
}

void setdp()
{
	for (int i = 1; i <= N; i++)
	{
		if (isPrime[i])
		{
			dp.push_back(i);
			dp[dp.size() - 1] += dp[dp.size() - 2];
		}
	}
}

void Solve()
{
	
	while (true)
	{

		if (front >= dp.size()) break;
		int Sum = dp[front] - dp[back];
		//cout << back << " " << front << " " << Sum << " " << res << endl;


		if (Sum < N)
		{
			front++;
		}
		else if (Sum > N)
		{
			back++;
		}

		else if (Sum == N)
		{
			res++;
			front++;
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	dp.push_back(0);
	
	setPrime();
	setdp();
	//show_dp();
	Solve();
	cout << res;


	return 0;
}



void show_prime()
{
	cout << "This is prime" << endl;
	for (int i = 1; i <= N; i++)
	{
		if (isPrime[i]) cout << i << " ";
	}
	cout << endl;
}

void show_dp()
{
	cout << "This is dp" << endl;
	for (auto& ele : dp)
		cout << ele << " ";
	cout << endl;
}