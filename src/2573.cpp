#include <iostream>

#define MAX_N 300

using namespace std;

int N, M;
int G[MAX_N + 1][MAX_N + 1];
int tempG[MAX_N + 1][MAX_N + 1];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // r, d, l, u
bool visited[MAX_N + 1][MAX_N + 1];

void initVisited() {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            visited[r][c] = false;
        }
    }
}

void initTempG() {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            tempG[r][c] = G[r][c];
        }
    }
}

void tempGtoG() {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            G[r][c] = tempG[r][c];
        }
    }
}

bool checkAllMelted() {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (G[r][c] > 0) return false;
        }
    }
    return true;
}

void dfs(int r, int c) {
    if (visited[r][c]) return;
    visited[r][c] = true;

    for (int i = 0; i < 4; ++i) {
        int nextR = r + dir[i][0], nextC = c + dir[i][1];
        // bound check
        if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M) continue;
        if (G[r][c] == 0) continue;
        dfs(nextR, nextC);
    }

}

bool checkMoreThan2() {
    // count 덩이
    int numIce = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) { 
            if (G[r][c] == 0) continue;
            if (visited[r][c]) continue;
            ++numIce;
            dfs(r, c);
        }
    }
    // cout << "numIce: " << numIce << "\n";
    return numIce >= 2;
}

void melt() {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (G[r][c] == 0) continue;
            
            int cntZero = 0;
            for (int i = 0; i < 4; ++i) {
                int nextR = r + dir[i][0], nextC = c + dir[i][1];
                // bound check
                if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M) continue;
                if (G[nextR][nextC] == 0) cntZero++;
            }
            tempG[r][c] = G[r][c] - cntZero;
            if (tempG[r][c] < 0) tempG[r][c] = 0;
            
        }
    }
}

void printG() {
    cout << "\n===========\n";
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cout << G[r][c] << " ";
        }
        cout << "\n";
    }
}

void getInput() {
    cin >> N >> M;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cin >> G[r][c];
        }
    }
}

int solve() {
    getInput();

    int cntYear = 0;
    if (checkMoreThan2()) {
        cout << cntYear << "\n";
        return 0;
    };
    initVisited();

    if (checkAllMelted()) {
        cout << 0; 
        return 0;
    }

    while (true) {
        // printG();
        cntYear++;
        melt();
        tempGtoG();
        if (checkMoreThan2()) {
            cout << cntYear << "\n";
            return 0;
        }
        initVisited();
        if (checkAllMelted()) {
            cout << 0; 
            return 0;
        }
        initTempG();
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    solve();

    return 0; 
}