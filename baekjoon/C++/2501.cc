#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> div_numbers;

void getDivNumbers() {
    
    for (int i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            div_numbers.push_back(i);
            if (i != (N / i))
                div_numbers.push_back(N / i);
        }
    }

    sort(div_numbers.begin(), div_numbers.end());
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    getDivNumbers();
    div_numbers.size() < K ? cout << 0 : cout << div_numbers[K-1];

    return (0);
}