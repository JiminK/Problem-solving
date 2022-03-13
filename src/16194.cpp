#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 1000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int dp[MAX_N + 1];
    int cost[MAX_N + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }
    for (int i = 0; i <= n; ++i) {
        dp[i] = 10000001;
    }

    dp[0] = 0;
    dp[1] = cost[1];
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j] + cost[j]);
            // cout << dp[i] << " ";
        }
        // cout << endl;
    }
    cout << dp[n] << "\n";

    return 0;
}