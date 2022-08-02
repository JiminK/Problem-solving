#include <iostream>

#define MAX_X 1000000 // coord MAX
#define MAX_N 100000  // bucket num MAX

using namespace std;

int N, K;
int coord[MAX_X + 1]; // 좌표 
long long maxSum;

void solve() {
    long long sum = 0;
    for (int i=0; i<=MAX_X; ++i) {
        if (i < 2*K + 1) {
            sum += coord[i];
            if (maxSum < sum) maxSum = sum;
            continue;
        }
        sum -= coord[i - (2*K + 1)];
        sum += coord[i];
        if (maxSum < sum) maxSum = sum;
    }
}

void getInput() {
    cin >> N >> K;
    for (int i=0; i<N; ++i) {
        int gi, xi; cin >> gi >> xi;
        coord[xi] = gi;
    }
    solve();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    cout << maxSum << "\n";

    return 0;
}