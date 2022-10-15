#include <iostream>
#include <deque>

using namespace std;

int N, K;
deque<int> dq;

// 1 2 3 4 5 6 7 
void solve() {
    cout << "<";
    while (!dq.empty()) {
        cout << dq[K] << ", ";
        dq.erase(dq.begin() + K);
    }
}

void getInput() {
    cin >> N >> K;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        dq.push_back(temp);
    }
    solve();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}