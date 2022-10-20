#include <iostream>

using namespace std;

int N, DP[1001];

void solve() {
    DP[1] = 1, DP[2] = 2;
    for (int i=3; i<=N; ++i) {
        DP[i] = (DP[i-1] + DP[i-2]) % 10007;
    }
    cout << DP[N];
}

void getInput() {
    cin >> N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    solve();

    return 0;
}