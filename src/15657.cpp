#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> num, v;

void dfs(int idx, int cnt) {
    if (cnt > M) {
        for (int i=0; i<v.size(); ++i)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }
    
    for (int i=idx; i<num.size(); ++i) {
        v.push_back(num[i]);
        dfs(i, cnt+1);
        v.pop_back();
    }
}

void getInput() {
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        num.push_back(temp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    sort(num.begin(), num.end());
    dfs(0, 1);

    return 0;
}