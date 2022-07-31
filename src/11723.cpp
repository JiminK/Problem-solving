#include <iostream>

using namespace std;

int M;
string cmd;
int num;
int arr[21];

void solve() {
    if (cmd == "add") {
        arr[num] = 1;
    }
    if (cmd == "remove") {
        arr[num] = 0;
    }
    if (cmd == "check") {
        cout << arr[num] << "\n";
    }
    if (cmd == "toggle") {
        if (arr[num]) arr[num] = 0;
        else arr[num] = 1;
    }
    if (cmd == "all") {
        for (int i=1; i<=20; ++i) {
            arr[i] = 1;
        }
    }
    if (cmd == "empty") {
        for (int i=1; i<=20; ++i) {
            arr[i] = 0;
        }
    }
}

// void printSet() {
//     cout << "\n============\n";
//     for (auto iter=mySet.begin(); iter!=mySet.end(); ++iter) {
//         // int curr = *iter;
//         cout << (*iter) << " ";
//     }
//     cout << "\n============\n";
// }

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