#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string str; cin >> str;
    string tmpStr;
    int minNum, secNum;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ':') {
            minNum = stoi(tmpStr);
            tmpStr = "";
            continue;
        }
        tmpStr.push_back(str[i]);
    }
    secNum = stoi(tmpStr);

    int cookTime = (minNum * 60) + secNum;
    
    int a = 10, b = 60, c = 600, start = 30;
    int cnt = 0;
    bool checked = false;

    // if (cookTime == start) {
    //     cout << 1 << "\n";
    //     return 0;
    // } 

    while (cookTime > 0) {
        if (cookTime >= c) {
            cookTime -= c;
            cnt++;
        } else if (cookTime >= b) {
            cookTime -= b;
            cnt++;
        } else if (cookTime >= start && checked == false) {
            cookTime -= start;
            cnt++;
            checked = true;
        } else if (cookTime >= a) {
            cookTime -= a;
            cnt++;
        }
    }
    if (checked == false) {
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}