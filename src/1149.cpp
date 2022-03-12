#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 1000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int dp[MAX_N + 1][3];
    int cost[MAX_N + 1][3];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> cost[i][j];
            // cout << cost[i][j];
        }
    }

    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        // cout << dp[i][0] << " " << cost[i][0] << ", ";
        // cout << dp[i - 1][1] << "\n";
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        // cout << dp[i][1] << " " << cost[i][1] << ", ";
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
        // cout << dp[i][2] << " " << cost[i][2] << "\n";

    }
    int minCost = min(dp[n][0], dp[n][1]);
    minCost = min(minCost, dp[n][2]);
    cout << minCost << "\n";
    
    return 0;
}
