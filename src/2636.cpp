#include <iostream>
#include <queue>

#define MAX_N 100

using namespace std;

int N, M;
int G[MAX_N + 1][MAX_N + 1];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // r, d, l, u
struct strt {
    int r, c;
};
bool visited[MAX_N + 1][MAX_N + 1];
queue <strt> q;

void getInput() {
    cin >> N >> M;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cin >> G[r][c];
        }
    }
}

void changeEdge() {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (r == 0 || c == 0 || r == N - 1 || c == M - 1)
                G[r][c] = 2;
        }
    }
}

void printG() {
    cout << "\n========\n";
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cout << G[r][c] << " ";
        }
        cout << "\n";
    }
}

void zero2two() { // bfs
    G[0][0] = 2; 
    q.push({0, 0}); 
    while (!q.empty()) {
        strt curr = q.front();
        int r = curr.r, c = curr.c;
        // int r = q.front().r, c = q.front().c;
        q.pop();
        // if (G[r][c] != 2) continue;
        for (int i = 0; i < 4; ++i) {
            int nextR = r + dir[i][0], nextC = c + dir[i][1];
            // bound check
            if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M) continue;
            if (!visited[nextR][nextC] && G[nextR][nextC] == 0) {
                q.push({nextR, nextC});
                G[nextR][nextC] = 2; 
                visited[nextR][nextC] = true;
            }
        }
    }
}

// void zero2two() { 
//     G[0][0] = 2;
//     for (int r = 0; r < N; ++r) {
//         for (int c = 0; c < M; ++c) {
//             if (G[r][c] != 2) continue;
//             for (int i = 0; i < 4; ++i) {
//                 int nextR = r + dir[i][0], nextC = c + dir[i][1];
//                 // bound check
//                 if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M) continue;
//                 if (G[nextR][nextC] == 1) continue;
//                 G[nextR][nextC] = 2; 
//                 // if (G[nextR][nextC] == 0) {
//                 //     G[nextR][nextC] = 2; 
//                 // }
//             }
//         }
//     }
// }

void melt() { // 2랑 붙어있는 1 -> 0
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (G[r][c] != 2) continue;
            for (int i = 0; i < 4; ++i) {
                int nextR = r + dir[i][0], nextC = c + dir[i][1];
                // bound check
                if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M) continue;
                if (G[nextR][nextC] == 1) {
                    G[nextR][nextC] = 0;
                }
            }
        }
    }
}

bool checkAllMelted() {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (G[r][c] != 0) return false;
        }
    }
    return true;
}

int countCheese() {
    int cnt = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (G[r][c] == 1) cnt++;
        }
    }
    return cnt;
}

void two2zero() { // 2 -> 0
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (G[r][c] == 2) 
                G[r][c] = 0;
        }
    }
}

void initVisited() {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            visited[r][c] = false;
        }
    }
}

void solve() {
    getInput();

    int cntHour = 0, cntCheese = 0;
    // 모두 녹았는지 확인
    if (checkAllMelted()) {
        cout << cntHour << "\n" << cntCheese << "\n";
        return;
    }

    while (true) {
        // 남아있는 치즈(1) 개수 카운팅
        // 모두 녹기 한 시간 전 치즈(1) 개수 필요
        cntCheese = countCheese();
        // cout << "cntCheese : " << cntCheese << "\n";

        // // 가장자리 0 -> 2 바꾸기
        // changeEdge();

        // 2 기준 4방향 탐색, 0 -> 2
        // 그냥 0 -> 2 하면 안됨.
        // => 구멍(0) 빼고 치즈(1)바깥에 있는 0만 2로 바꿔야 하기 때문
        zero2two();
        // printG();

        // 2 기준 4방향 탐색, 1 -> 0 
        melt();
        // printG();

        // 2 -> 0
        two2zero();
        // printG();

        initVisited();
        cntHour++;
        
        // 모두 녹았는지 확인 
        if (checkAllMelted()) {
            cout << cntHour << "\n" << cntCheese << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}