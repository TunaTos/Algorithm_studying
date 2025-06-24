
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(const vector<long long>& A, long long target, int exclude_index) {
    int left = 0, right = A.size() - 1;
    
    while (left < right) {
        if (left == exclude_index) {
            left++;
        } else if (right == exclude_index) {
            right--;
        } else {
            long long sum = A[left] + A[right];
            if (sum == target) return true;
            else if (sum < target) left++;
            else right--;
        }
    }
    
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    int goodCount = 0;
    
    for (int i = 0; i < N; i++) {
        long long target = A[i];
        if (binary_search(A, target, i)) {
            goodCount++;
        }
    }
    
    cout << goodCount << endl;
    
    return 0;
}
