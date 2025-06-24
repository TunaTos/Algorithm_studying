#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;
using ull = unsigned long long;

vector<ull> primeFactors;

void primeFactorization(ull n) {
    primeFactors.clear(); 

    if (n % 2 == 0) {
        primeFactors.push_back(2);
        while (n % 2 == 0) {
            n /= 2;
        }
    }

    for (ull i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            primeFactors.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    if (n > 1) {
        primeFactors.push_back(n);
    }
}

ull eulerTotient(ull n) {
    ull result = n; 

    for (ull p : primeFactors) 
        result -= result / p;
    

    return result;
}

int main(void) {
    // ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ull n;
    cin >> n;

    if (n == 1) {
        cout << 1;
    } else {
        primeFactorization(n);
        cout << eulerTotient(n);
    }

    return 0;
}