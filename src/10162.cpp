#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    int a = 300, b = 60, c = 10; // 5min, 1min, 10sec 
    int cntA = 0, cntB = 0, cntC = 0;

    while (true) {
        if (t == 0) {
            cout << cntA << " " << cntB << " " << cntC  << "\n";
            return 0;
        } else if (t >= a) {
            t -= a;
            cntA++;
        } else if (t >= b) {
            t -= b;
            cntB++;
        } else if (t >= c) {
            t -= c;
            cntC++;
        } else if (t < c) {
            cout << -1 << "\n";
            return 0;
        }
    }
}