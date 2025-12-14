#include <bits/stdc++.h>
#define endl '\n'
#define MAX 100000
using namespace std;


string str;
vector<bool> eratos(MAX+1, true);

void set_eratos() {	
	eratos[0] = false;
	eratos[1] = false;
	
	for (int i = 2; i <= sqrt(MAX); i++) {
		if (eratos[i]) {  
			for (int j = i * i; j <= MAX; j += i)  
				eratos[j] = false;
		}
	}
}


int traverse(int N, string str) {
	
	int res = -1;
	int size = str.size();
	for (int i = 0; i <= size - N; ++i)
	{
		string s = str.substr(i, N);
		
		if (stoi(s) > MAX) continue;
		if (eratos[stoi(s)]) {
			res = max(res, stoi(s));
		}
	}
	return res;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	set_eratos();

	while (true) {
		cin >> str;

		if (str == "0") 
			break;
		int res = 0;
		for (int i = 6; i >= 1; i--)
		{
			res = max(res,traverse(i, str));
		}
		cout << res << endl;
	}

	return (0);
}