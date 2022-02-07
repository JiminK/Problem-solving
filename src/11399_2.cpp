#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000 + 1

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int timeArr[MAX_N];
    for (int i = 0; i < n; ++i) {
        cin >> timeArr[i];
    }
    sort(timeArr, timeArr + n);
    int minTime = 0;
    for (int i = 0; i < n; ++i) {
        minTime += timeArr[i] * (n - i);
    }
    cout << minTime << "\n";
    return 0;
}