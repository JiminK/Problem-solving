#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, num;
    string myCmd;
    queue<int> q;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> myCmd;
        if (myCmd == "push") {
            cin >> num;
            q.push(num);
        }
        if (myCmd == "pop") {
            if (q.empty())
                cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        if (myCmd == "size")
            cout << q.size() << "\n";
        if (myCmd == "empty") {
            if (q.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        if (myCmd == "front") {
            if (q.empty())
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";
        }
        if (myCmd == "back") {
            if (q.empty())
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";
        }
    }

    return 0;
}
