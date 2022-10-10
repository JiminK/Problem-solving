#include <iostream>
#include <queue>

#define MAXI 300 

using namespace std;

int T, I;
struct strt {
    int r, c;
    int cost;
};
int G[MAXI+1][MAXI+1];
bool check[MAXI+1][MAXI+1];
queue<strt> q;
int dir[8][2] = {{-1, -2}, {-2, -1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {1, 2}, {2, 1}};
int mini;

void bfs(int r, int c) {
    q.push({r, c, 0});
    check[r][c] = true;
    while (!q.empty()) {
        int currR = q.front().r, currC = q.front().c; 
        int cost = q.front().cost;
        q.pop();
        for (int i=0; i<8; ++i) {
            int nextR = currR + dir[i][0], nextC = currC + dir[i][1];
            if (nextR < 0 || nextR >= I || nextC < 0 || nextC >= I) continue;
            if (check[nextR][nextC]) continue;
            if (G[nextR][nextC] == 1) {
                mini = cost + 1;
                return;
            }
            q.push({nextR, nextC, cost+1});
            check[nextR][nextC] = true;
        }
    }
}

void solve(int r, int c) {
    bfs(r, c);
    cout << mini << "\n";
}

void init() {
    for (int i=0; i<MAXI; ++i) {
        for (int j=0; j<MAXI; ++j) {
            check[i][j] = false;
        }
    }
    for (int i=0; i<MAXI; ++i) {
        for (int j=0; j<MAXI; ++j) {
            G[i][j] = false;
        }
    }
    mini = 0;
    while(!q.empty()) q.pop();
}

void getInput() {
    cin >> T;
    for (int i=0; i<T; ++i) {
        cin >> I; // 한 변의 길이
        int r, c; cin >> r >> c;
        int destR, destC; cin >> destR >> destC;
        G[destR][destC] = 1;

        solve(r, c);
        init();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}