#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
vector<int> v;
stack<int> stk;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        v.push_back(temp);
    }

    stk.push(v[N-1]);
    for (int i=N-2; i>=0; --i) {
        if (v[i] > stk.top()) {
            stk.push(v[i]);
        }
    }

    cout << stk.size() << "\n";

    return 0;
}