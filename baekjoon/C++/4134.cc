#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define endl '\n'
using namespace std;

int N;
long long num;

bool is_prime(const long long& n) {

    
    for (size_t i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) 
            return false;    
    }
    return true;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        
        if (num == 0 || num == 1) {
            cout << 2 << endl;
            continue;
        }
        while (true) {
            if (is_prime(num)) {
                cout << num << endl;
                break;
            }
            ++num;
        }
    }

    return (0);
}