#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> minHeap;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        if (temp == 0) {
            if (minHeap.empty()) {
                cout << 0 << "\n";
                continue;
            }
            cout << minHeap.top() << "\n";
            minHeap.pop();
            continue;
        }
        minHeap.push(temp);
    }

    return 0;
}