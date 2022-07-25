#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int> maxHeap;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        if (temp == 0) {
            if (maxHeap.empty()) {
                cout << 0 << "\n";
                continue;
            }
            cout << maxHeap.top() << "\n";
            maxHeap.pop();
            continue;
        }
        maxHeap.push(temp);
    }

    return 0;
}