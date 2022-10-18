#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C, ans;
int board[21][21];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool check[26];

void dfs(int r, int c, int cnt) {
    ans = max(ans, cnt);
    for (int i=0; i<4; ++i) {
        int nextR = r + dir[i][0], nextC = c + dir[i][1];
        if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
        if (check[board[nextR][nextC]]) continue;
        check[board[nextR][nextC]] = true;
        dfs(nextR, nextC, cnt+1);
        check[board[nextR][nextC]] = false;
    }
}

void getInput() {
    cin >> R >> C;
    for (int i=0; i<R; ++i) {
        string st; cin >> st;
        for (int j=0; j<C; ++j) {
            board[i][j] = st[j] - 'A';
            // cout << board[i][j] << " ";
        }
        // cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    check[board[0][0]] = true;
    dfs(0, 0, 1);
    cout << ans << "\n";

    return 0;
}