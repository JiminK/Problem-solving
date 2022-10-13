#include <iostream>
#include <queue>

#define MAX_N 1000

using namespace std;

int N, M;
int MAP[MAX_N + 1][MAX_N + 1];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
struct strt {
    int r, c;
    int cnt; // 최단거리 카운팅
    int wallCnt; // 부순 벽 체크
};
queue<strt> q;
// 벽을 안 부순 경우와 부순 경우를 따로 방문 체크해야함!
int check[MAX_N + 1][MAX_N + 1][2];

int bfs() {
    q.push({0, 0, 1, 0});
    check[0][0][0] = 1;
    while(!q.empty()) {
        int currR = q.front().r, currC = q.front().c;
        int currCnt = q.front().cnt;
        int currWall = q.front().wallCnt;
        q.pop();

        if (currR == N-1 && currC == M-1) return currCnt;
        for (int i=0; i<4; ++i) {
            int nextR = currR + dir[i][0], nextC = currC + dir[i][1];
            // bound check
            if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M) continue;
            // visited check
            if (check[nextR][nextC][currWall]) continue;
            
            // 빈칸 만난 경우 
            if (MAP[nextR][nextC] == 0) {
                q.push({nextR, nextC, currCnt+1, currWall});
                check[nextR][nextC][currWall] = 1;
                continue;
            }

            // 벽을 안 부순 상태에서 벽 만난 경우
            if (currWall == 0) {
                if (MAP[nextR][nextC] == 1) { // && q.front().wallCnt == false
                    q.push({nextR, nextC, currCnt+1, 1});
                    check[nextR][nextC][1] = 1;
                    continue;
                }
            }
            
            // 이미 1개 부순 상태에서 벽 만난 경우
            if (currWall == 1 && MAP[nextR][nextC] == 1) continue; 
        }
    }
    return -1;
}

void solve() {
    cout << bfs() << "\n";
}

void getInput() {
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        string tempStr; cin >> tempStr;
        for (int j=0; j<M; ++j) {
            MAP[i][j] = tempStr[j] - '0';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    solve();

    return 0;
}