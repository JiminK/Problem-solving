#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        int tmpN = i;
        int tmpSum = 0, sum = 0;
        while (tmpN != 0) {
            int tmp = tmpN % 10;
            tmpSum += tmp;
            tmpN /= 10;
        }
        // cout << "tmpSum : " << tmpSum << "\n";
        sum = i + tmpSum;
        // cout << "sum : " << sum << "\n";
        if (sum == n) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
    return 0;
}