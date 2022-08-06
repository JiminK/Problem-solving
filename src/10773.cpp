#include <iostream>
#include <stack>

using namespace std;

int K;
stack<int> stk;
int sum;

void solve(int num) {
    if (num == 0) {
        sum -= stk.top();
        stk.pop();
        return;
    }
     stk.push(num);
     sum += num;   
}

void getInput() {
    cin >> K;
    for (int i=0; i<K; ++i) {
        int num; cin >> num;
        solve(num);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    cout << sum << "\n";

    return 0;
}