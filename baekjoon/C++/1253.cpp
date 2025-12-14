#define _CRT_SECURE_NO_WARNIGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void IsGoodNum(vector<int> A, const int Target, int& Result);


int main() 
{
	int Len;
	cin >> Len;
	int Result = 0;//정답

	vector<int> A;
	

	for (int i = 0; i < Len; i++)
	{
		int B;
		cin >> B;
		A.push_back(B);
	}//입력부

	sort(A.begin(), A.end());//정렬


	for (int i = 0; i < Len; i++)
	{
		IsGoodNum(A, i, Result);
	}

	cout << Result << endl;


	

	return 0;

}

void IsGoodNum(const vector<int> A, const int idx, int& Result)
{
	int Len = A.size();//벡터의 길이
	int First = 0;
	int Last = Len - 1;

	
	while (First<Last) // 투 포인터가 교차될 때 까지
	{
		int Sum = A[First] + A[Last];

		if (Sum==A[idx])
		{
			if (First!=idx&&Last!=idx)
			{
				Result++;
				break;
			}
			else if (First==idx)
				First++;
			else if (Last==idx)
				Last--;	
		}
		else if (Sum < A[idx])//sum이 더 작은 경우에
			First++;
		
		else if (Sum>A[idx])
			Last--;

	}
}

