#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void dfs(int idx, int cnt) {
    if (cnt > M) {
        for (int i=0; i<M; ++i)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }

    for (int i=idx; i<=N; ++i) {
        v.push_back(i);
        dfs(i, cnt+1);
        v.pop_back();
    }
}

void getInput() {
    cin >> N >> M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    dfs(1, 1);

    return 0;
}