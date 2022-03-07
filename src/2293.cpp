#include <iostream>

using namespace std;

#define MAX_N 100

int main() {
    int n, k;
    cin >> n >> k;
    int arr[MAX_N + 1];
    int dp[MAX_N + 1];

    // a(k) = b(n) + b(n-1) + b(n-2) + ... + b(1)
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i] += arr[j];

        }
    }
    cout << dp[k] << "\n";
    return 0;
}