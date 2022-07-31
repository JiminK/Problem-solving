#include <iostream>
#include <unordered_set>

using namespace std;

int M;
string cmd;
int num;
unordered_set<int> mySet;

void solve() {
    if (cmd == "add") {
        mySet.insert(num);
    }
    if (cmd == "remove") {
        mySet.erase(num);
    }
    if (cmd == "check") {
        cout << mySet.count(num) << "\n";
    }
    if (cmd == "toggle") {
        if (mySet.count(num)) mySet.erase(num);
        else mySet.insert(num);
    }
    if (cmd == "all") {
        mySet.clear();
        for (int i=1; i<=20; ++i) {
            mySet.insert(i);
        }
    }
    if (cmd == "empty") {
        mySet.clear();
    }
}

void printSet() {
    cout << "\n============\n";
    for (auto iter=mySet.begin(); iter!=mySet.end(); ++iter) {
        // int curr = *iter;
        cout << (*iter) << " ";
    }
    cout << "\n============\n";
}

void getInput() {
    cin >> M;
    for (int i=0; i<M; ++i) {
        cin >> cmd;
        if (cmd == "all" || cmd == "empty") solve();
        else {
            cin >> num;
            solve();
        }
        // printSet();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}