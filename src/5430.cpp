#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int T, N;
string p;
deque<int> dq;
char cmd;
bool isReversed;

// void printAnswer() {
//     for (int i=0; i<dq.size(); ++i) {
//         cout << dq[i]
//     }
// }

// void solve() {
//     for (int i=0; i<p.size(); ++i) {
//         cmd = p[i];
//         if (cmd == 'R') {
//             dq.
//         }
//         if (cmd == 'D') {
//             if (dq.empty()) {
//                 cout << "error" << "\n";
//                 return;
//             }
//             dq.pop_front();
//         }
//     }
//     printAnswer();
// }

void getInput() {
    cin >> T;
    for (int i=0; i<T; ++i) {
        cin >> p >> N;
        string tempArr; cin >> tempArr;
        for (int j=0; j<tempArr.size(); ++j) {
            int tempNum = tempArr[j];
            if (isdigit(tempNum)) dq.push_back(tempNum);
        }
        for (int j=0; j<dq.size(); ++j) {
            cout << dq.front() << ", ";
            dq.pop_front();
        }
        // solve();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}