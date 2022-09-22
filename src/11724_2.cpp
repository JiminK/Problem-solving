#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> vec[1001];
bool checked[1001];
int cnt;

void dfs(int idx) {
    if (checked[idx]) return;
    checked[idx] = 1;
    for (int i=0; i<vec[idx].size(); ++i) {
        dfs(vec[idx][i]);
    }
}

void getInput() {
    cin >> N >> M;
    for (int i=0; i<M; ++i) {
        int a, b; cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for (int i=1; i<=N; ++i) { // 모든 정점에 대해 dfs 를 시도할 것임. (범위 주의!)
        if (checked[i]) continue; // 근데 이미 방문 했으면 넘어갈 것임.
        dfs(i); // 첫번째 정점부터 순서대로 dfs 를 시도
        cnt++; // dfs 를 호출한 횟수가 연결 요소의 개수!
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    cout << cnt << "\n";

    return 0;
}