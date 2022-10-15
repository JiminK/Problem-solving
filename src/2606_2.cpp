#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vec[101];
bool checked[101];
int cnt;

void dfs(int v) {
    if (checked[v]) return;
    checked[v] = 1;
    cnt++;
    for (int i=0; i<vec[v].size(); ++i) {
        dfs(vec[v][i]);
    }
}

void getInput() {
    cin >> N >> M;
    for (int i=0; i<M; ++i) {
        int a, b; cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    cout << cnt - 1 << "\n";

    return 0;
}