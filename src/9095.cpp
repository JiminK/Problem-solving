#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int dpFunc(int n) {
    if (n == 1) 

    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n; cin >> t >> n;
    for (int i = 0; i < t; ++i) {
        
        cout << dpFunc(n) << "\n";
    }
    return 0;
}