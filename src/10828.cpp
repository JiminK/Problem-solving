#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N;
string cmd;
stack<int> stk;

void solve(string &cmd, int &temp) { 
    // cout << cmd << "\n";
    if (cmd == "push") {
        stk.push(temp);
    } 
    if (cmd == "pop") {
        if (stk.empty()) cout << -1 << "\n";
        else { 
            cout << stk.top() << "\n";
            stk.pop();
        }
    }
    if (cmd == "size") {
        cout << stk.size() << "\n";
    } 
    if (cmd == "empty") {
        if (stk.empty()) cout << 1 << "\n";
        else cout << 0 << "\n";
    } 
    if (cmd == "top") {
        if (stk.empty()) cout << -1 << "\n";
        else cout << stk.top() << "\n";
    }
}

void getInput() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> cmd;
        int temp;
        if (cmd == "push") {
            cin >> temp;
            solve(cmd, temp);
        } else solve(cmd, temp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}