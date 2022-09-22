#include <iostream>
#include <vector>

using namespace std;

int T, M, N, K;
int arr[51][51];
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
bool visited[51][51];
int cnt;

void dfs(int r, int c) {
    if (visited[r][c]) return;
    visited[r][c] = 1;
    for (int i=0; i<4; ++i) {
        int nextR = r + dir[i][0], nextC = c + dir[i][1];
        if (nextR < 0 || nextR >= M || nextC < 0 || nextC >= N) continue;
        if (arr[nextR][nextC] == 0) continue;
        dfs(nextR, nextC);
    }
}

void init() {
    for (int i=0; i<51; ++i) {
        for (int j=0; j<51; ++j) {
            arr[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    cnt = 0;
}

void getInput() {
    cin >> T;
    for (int t=0; t<T; ++t) {
        init();
        cin >> M >> N >> K;
        for (int i=0; i<K; ++i) {
            int r, c; cin >> r >> c;
            arr[r][c] = 1;
        }
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j) {
                if (arr[i][j] == 0 || visited[i][j] == 1) continue;
                dfs(i, j);
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}