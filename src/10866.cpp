#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque<int> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string cmd; cin >> cmd;
        if (cmd.compare("push_front") == 0) {
            int x; cin >> x;
            dq.push_front(x);
        } else if (cmd.compare("push_back") == 0) {
            int x; cin >> x;
            dq.push_back(x);
        } else if (cmd.compare("pop_front") == 0) {
            if (dq.empty())
                cout << -1 << "\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        } else if (cmd.compare("pop_back") == 0) {
            if (dq.empty())
                cout << -1 << "\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        } else if (cmd.compare("size") == 0) {
            cout << dq.size() << "\n";
        } else if (cmd.compare("empty") == 0) {
            if (dq.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if (cmd.compare("front") == 0) {
            if (dq.empty())
                cout << -1 << "\n";
            else
                cout << dq.front() << "\n";
        } else if (cmd.compare("back") == 0) {
            if (dq.empty())
                cout << -1 << "\n";
            else 
                cout << dq.back() << "\n";
        }
    }
    return 0;
}