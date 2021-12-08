#include <iostream>
#include <vector>
using namespace std;

int N, n;
string cmd;
vector<int> v;

void pushFunc(string cmd, int n) {
    v.push_back(n);
}

void popFunc(string cmd) {
    if (!v.empty()) {
        cout << v.back();
        v.pop_back();
    }
    else
        cout << -1;
    cout << endl;
}

void sizeFunc(string cmd) {
    cout << v.size();
    cout << endl;
}

void emptyFunc(string cmd) {
    if (!v.empty())
        cout << 0;
    else
        cout << 1;
    cout << endl;
}

void topFunc(string cmd) {
    if (!v.empty())
        cout << v.back();
    else
        cout << -1;
    cout << endl;
}



int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> n;
            pushFunc(cmd, n);
        }
        if (cmd == "pop") 
            popFunc(cmd);
        if (cmd == "size") 
            sizeFunc(cmd);
        if (cmd == "empty")
            emptyFunc(cmd);
        if (cmd == "top")
            topFunc(cmd);
    }
    return 0;
}
