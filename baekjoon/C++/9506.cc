#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int N;
vector<int> div_numbers;

void solve() {
    
    for (int i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            div_numbers.push_back(i);
            if (i != N / i) {
                div_numbers.push_back(N / i);
            }
        }
    }
    sort(div_numbers.begin(), div_numbers.end());

    int sum = 0;
        for (int j = 0; j < div_numbers.size() -1; ++j) {
            sum += div_numbers[j];
        }

        if (sum == N) {
            cout << N << " = ";
            for (int z = 0; z <div_numbers.size() -1; ++z) {
                cout << div_numbers[z];
                if (z != div_numbers.size() - 2)
                    cout << " + ";
            }cout << endl;
        }
        else {
            cout << N << " is NOT perfect.\n";
        }

    div_numbers.clear();

}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    while (true) {
        cin >> N;
        
        if (N == -1) break;
        solve();
    }


    return (0); 
}