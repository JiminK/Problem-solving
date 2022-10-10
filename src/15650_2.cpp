#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool check[9];
vector<int> v;

void dfs(int idx, int cnt) {
    if (cnt > M) {
        for (int i=0; i<v.size(); ++i)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }

    for (int i=idx; i<=N; ++i) {
        if (check[i]) continue;
        check[i] = true;
        v.push_back(i);
        dfs(i+1, cnt+1);
        v.pop_back();
        check[i] = false;
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