#include <iostream>
#include <algorithm>

using namespace std;

long long count_less_equal(int N, long long mid) {
    long long count = 0;
    for (int i = 1; i <= N; i++) {
        count += min(mid / i, (long long)N);
    }
    return count;
}

int main() {
    int N;
    long long k;
    cin >> N >> k;

    long long low = 1, high = (long long)N * N;
    long long answer = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (count_less_equal(N, mid) >= k) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}
