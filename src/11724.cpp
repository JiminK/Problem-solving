#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> vec[1001];
queue<int> q;
bool checked[1001];
int cnt;

void bfs(int s) {
    q.push(s);
    checked[s] = 1; // 바로 방문 체크 필수!
    while(!q.empty()) {
        int idx = q.front(); q.pop();

        for (int i = 0; i < vec[idx].size(); ++i) {
            if (checked[vec[idx][i]]) continue;
            q.push(vec[idx][i]);
            checked[vec[idx][i]] = 1;
        }
    }
}

void getInput() {
    cin >> N >> M;
    for (int i=0; i<M; ++i) {
        int a, b; cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for (int i=1; i<=N; ++i) { // 모든 정점에 대해 bfs 를 시도할 것임. (범위 주의!)
        if (checked[i]) continue; // 근데 이미 방문 했으면 넘어갈 것임.
        bfs(i); // 첫번째 정점부터 순서대로 bfs 를 시도
        cnt++; // bfs 를 호출한 횟수가 연결 요소의 개수!
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    cout << cnt << "\n";

    return 0;
}