#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 1000

int N;
int TIME[MAX_N+1];
int minTime;

void getInput() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> TIME[i];
    }
}

void solve() {
    sort(TIME, TIME+N);
    for (int i=0; i<N; ++i) {
        minTime += TIME[i] * (N-i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    solve();

    cout << minTime << "\n";

    return 0;
}