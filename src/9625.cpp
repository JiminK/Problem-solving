#include <iostream>
#include <string>

using namespace std;

void countAB(string str) {
    int cntA = 0, cntB = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == 'A') {
            cntA++;
        } else {
            cntB++;
        }
    }
    cout << cntA << " " << cntB << "\n";
}

string pushBtn(string str) {
    string newStr = "";
    for (int i = 0; i < str.length(); ++i) {
        // cout << "str[i] " << str[i] << endl;
        if (str[i] == 'A') {
            newStr.push_back('B');
            // cout << 0 << newStr << "\n";

        } if (str[i] == 'B') {
            newStr.push_back('B');
            // cout << 1 << newStr << "\n";
            newStr.push_back('A');
            // cout << 2 << newStr << "\n";

        }
    }
    // cout << newStr << "\n";
    return newStr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k; cin >> k;
    string str = "A";
    while (k > 0) {
        str = pushBtn(str);
        k--;
    }
    countAB(str);
    return 0;
}