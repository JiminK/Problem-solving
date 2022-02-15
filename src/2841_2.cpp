#include <iostream>
#include <stack>

using namespace std;

int n, p;
int cnt = 0;
stack<int> stk[7];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> p;
    for (int i = 0; i < n; ++i) {
        int nowN, nowF;
        cin >> nowN >> nowF;

        // if (stk[nowN].empty()) {
        //     stk[nowN].push(nowF);
        //     cnt++;
        //     continue;
        // }

        while (stk[nowN].empty() == false) {
            if (stk[nowN].top() > nowF) {
                stk[nowN].pop();
                cnt++;
            } else {
                break;
            }
        }
        if (stk[nowN].empty() == false) {
            if (stk[nowN].top() == nowF) {
                continue;
            }
        }
        stk[nowN].push(nowF);
        cnt++;
        
    }
    cout << cnt << "\n";

    return 0;
}