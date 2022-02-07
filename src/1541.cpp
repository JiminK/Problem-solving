#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> num;
    vector<char> op;

    string str; cin >> str;
    string tmpNum;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '+' || str[i] == '-') {
            op.push_back(str[i]);
            num.push_back(stoi(tmpNum));
            tmpNum = "";
            continue;
        }
        tmpNum.push_back(str[i]);
    }
    num.push_back(stoi(tmpNum));
    
    // for (int i = 0; i < num.size(); ++i) {
    //     cout << num[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 0; i < op.size(); ++i) {
    //     cout << op[i] << " ";
    // }
    if (op.size() == 0) {
        cout << num[0] << "\n";
        return 0;
    }
    for (int i = 0; i < op.size() - 1; ++i) {
        if (op[i] == '-') {
            op[i + 1] = '-';
        }
    }
    for (int i = 0; i < num.size() - 1; ++i) {
        if (op[i] == '+') 
            num[i + 1] += num[i];
        if (op[i] == '-')
            num[i + 1] = num[i] - num[i + 1];
    }
    cout << num[num.size() - 1] << "\n";   
    return 0;
}