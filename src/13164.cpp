#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    vector<int> diffHeight(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        diffHeight[i] = heights[i + 1] - heights[i];
    }
    sort(diffHeight.begin(), diffHeight.end());

    long long minCost = 0;
    for (int i = 0; i < n - k; ++i) {
        minCost += diffHeight[i];
    }
    cout << minCost << "\n";

    return 0;
}