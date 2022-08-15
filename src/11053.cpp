#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> vec;

void solve(vector<int> dp) {
    for (int i=1; i<vec.size(); ++i) {
        for (int j=0; j<i; ++j) {
            if (vec[i] > vec[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = -1;
    for (int i=0; i<dp.size(); ++i) {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}

void getInput() {
    cin >> N;
    vector<int> dp(N+1, 1);
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        vec.push_back(temp);
    }
    solve(dp);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}