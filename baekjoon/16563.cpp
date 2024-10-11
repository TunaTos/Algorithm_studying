#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAX_NUM 5000000
using namespace std;

int Tcase, K;
bool isPrime[MAX_NUM+1]; // 특정 수 N이 소수인가를 나타냄
int minPrime[MAX_NUM+1]; // 특정 수N의 가장 작은 소수를 나타냄

//Function For Debug
void show_Eratos();
void show_minPrime();


void Init()
{
	memset(isPrime, true, sizeof(isPrime)); // 모두 true값으로 만듦
	for (int i = 1; i <= MAX_NUM; i++)
		minPrime[i] = i;

	isPrime[0] = isPrime[1] = false; // 0과 1은 false처리함

	int sqrtN = int(sqrt(MAX_NUM));


	for (int i = 2; i <= sqrtN; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= MAX_NUM; j += i)
			{
				if (isPrime[j])
				{
					minPrime[j] = min(minPrime[j], i);
				}
				isPrime[j] = false;
			}
		}
	}
}

void Solve(int num)
{
	while (1)
	{
		if (num == minPrime[num])
		{
			cout << num << '\n';
			break;
		}
		else
		{
			cout << minPrime[num] << " ";
			num /= minPrime[num];
		}
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int input;

	cin >> Tcase;

	Init();

	for (int i = 0; i < Tcase; i++)
	{
		cin >> input;
		Solve(input);
	}



	return 0;
}


void show_Eratos()
{
	cout << "This is Eratos" << endl;
	for (size_t i = 1; i <= MAX_NUM; i++)
	{
		if (isPrime[i]) cout << i << " ";
	}cout << endl;
}

void show_minPrime()
{
	cout << "This is minPrime" << endl;
	for (size_t i = 1; i <= MAX_NUM; i++)
	{
		cout << minPrime[i] << " ";
	}cout << endl;
}