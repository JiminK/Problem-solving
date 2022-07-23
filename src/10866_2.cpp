#include <iostream>
#include <deque>

using namespace std;

int N;
string cmd;
deque<int> dq;

void solve(string cmd, int temp) {
    if (cmd == "push_front") {
        dq.push_front(temp);
    }
    if (cmd == "push_back") {
        dq.push_back(temp);
    }
    if (cmd == "pop_front") {
        if (dq.empty()) cout << -1 << "\n";
        else {
            cout << dq.front() << "\n";
            dq.pop_front();
        }
    }
    if (cmd == "pop_back") {
        if (dq.empty()) cout << -1 << "\n";
        else {
            cout << dq.back() << "\n";
            dq.pop_back();
        }
    }
    if (cmd == "size") {
        cout << dq.size() << "\n";
    }
    if (cmd == "empty") {
        if (dq.empty()) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    if (cmd == "front") {
        if (dq.empty()) cout << -1 << "\n";
        else cout << dq.front() << "\n";
    }
    if (cmd == "back") {
        if (dq.empty()) cout << -1 << "\n";
        else cout << dq.back() << "\n";
    }
}

void getInput() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> cmd;
        int temp;
        if (cmd == "push_front" || cmd == "push_back") {
            cin >> temp; solve(cmd, temp);
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