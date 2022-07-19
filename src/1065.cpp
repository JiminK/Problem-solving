#include <iostream>
#include <vector>

using namespace std;

int N;
int cnt;

bool checkDiff(int i) {
    vector<int> num;
    if (i == 1000) cnt -= 1;
    // cout << "i : " << i << "\n";
    while (i > 0) {
        num.push_back(i % 10); 
        i /= 10;
    }
    // cout << num[0] << ", " << num[1] << ", " << num[2] << "\n";
    if ((num[2]-num[1]) == (num[1]-num[0])) 
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    if (N < 100) {
        cnt = N;
    }
    else if (N >= 100) {
        cnt += 99;
        for (int i=100; i<=N; ++i) {
            if (checkDiff(i)) ++cnt;
            // cout << "cnt: " << cnt << "\n"; 
        }
    }
    cout << cnt << "\n";

    return 0;
}