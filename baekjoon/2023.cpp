#include <iostream>
#include <vector>
#include <cmath>
#include <initializer_list>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void findInterestingPrimes(int current, int length, int N, vector<int>& results) {
    if (length == N) {
        results.push_back(current);
        return;
    }

    for (int digit = 1; digit <= 9; digit++) {
        int next = current * 10 + digit;
        if (isPrime(next)) { 
            findInterestingPrimes(next, length + 1, N, results);
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> results;
    for (int prime : {2, 3, 5, 7}) {
        findInterestingPrimes(prime, 1, N, results);
    }

    for (int num : results) {
        cout << num << '\n';
    }

    return 0;
}