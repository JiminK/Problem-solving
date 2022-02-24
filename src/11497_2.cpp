#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_N 10000 + 1

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    for (int i = 0; i < t; ++i) {
        int n; cin >> n;
        int height[MAX_N];
        vector<int> newHeight;

        for (int i = 0; i < n; ++i) 
            cin >> height[i];
        sort(height, height + n);

        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0)
                newHeight.push_back(height[i]);
        }
        for (int i = n - 1; i > 0; --i) {
            if (i % 2 != 0)
                newHeight.push_back(height[i]);
        }
        // cout << "newHeight" << "\n";
        // for (int i = 0; i < n; ++i) {
        //     cout << newHeight[i] << "\n";
        // }

        for (int i = 0; i < n - 1; ++i)
            height[i] = abs(newHeight[i + 1] - newHeight[i]);
        height[n - 1] = abs(newHeight[n - 1] - newHeight[0]);
        // for (int i = 0; i < n; ++i) {
        //     cout << i << ": " << height[i] << "\n";
        // }

        sort(height, height + n);
        cout << height[n - 1] << "\n";
    }
    return 0;
}