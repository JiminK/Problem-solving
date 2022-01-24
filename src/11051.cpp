#include <iostream>

using namespace std;

#define MAX_N 1001

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);

    int N, K;
    int dp[MAX_N][MAX_N];
    cin >> N >> K; 
 
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            if (j == 0) 
                dp[i][j] = 1;
            if (i == j) 
                dp[i][j] = 1;
            else 
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

            dp[i][j] = dp[i][j] % 10007;
            // cout << dp[i][j] << "\n";
        }
    }
    cout << dp[N][K] % 10007 << "\n";
    return 0;
}

