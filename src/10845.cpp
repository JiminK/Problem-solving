#include <iostream>
#include <queue>

using namespace std;

int N;
string cmd;
queue<int> q;

void solve(string cmd, int temp) {
    if (cmd == "push") {
        q.push(temp);
    }
    if (cmd == "pop") {
        if (q.empty()) cout << -1 << "\n";
        else {
            cout << q.front() << "\n";
            q.pop();
        }
    }
    if (cmd == "size") {
        cout << q.size() << "\n";
    }
    if (cmd == "empty") {
        if (q.empty()) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    if (cmd == "front") {
        if (q.empty()) cout << -1 << "\n";
        else {
            cout << q.front() << "\n";
        }
    }
    if (cmd == "back") {
        if (q.empty()) cout << -1 << "\n";
        else {
            cout << q.back() << "\n";
        }
    }
}

void getInput() {
    cin >> N;
    int temp;
    for (int i=0; i<N; ++i) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> temp;
            solve(cmd, temp);
        }
        else solve(cmd, temp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}