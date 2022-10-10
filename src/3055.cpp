#include <iostream>
#include <queue>
#include <vector>

#define MAXR 50
using namespace std;

int R, C;
struct strt {
    int r, c;
    int time;
};
queue<strt> SQ;     // 고슴도치 
queue<strt> waterQ; // 물
char G[MAXR+1][MAXR+1];
bool check[MAXR+1][MAXR+1][2];
int floodTime[MAXR+1][MAXR+1];
vector<strt> vec;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

// 홍수 BFS
void waterBfs() {
    for (int i=0; i<vec.size(); ++i) {
        waterQ.push({vec[i].r, vec[i].c, 0});
        check[vec[i].r][vec[i].c][0] = true;
    }
    while (!waterQ.empty()) {
        int currR = waterQ.front().r, currC = waterQ.front().c, time = waterQ.front().time;
        waterQ.pop();
        for (int i=0; i<4; ++i) {
            int nextR = currR + dir[i][0], nextC = currC + dir[i][1];
            if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
            if (check[nextR][nextC][0]) continue;
            if (G[nextR][nextC] == 'X' || G[nextR][nextC] == 'D' || G[nextR][nextC] == 'S') {
                floodTime[nextR][nextC] = 20000;
                continue;
            }
            waterQ.push({nextR, nextC, time+1});
            check[nextR][nextC][0] = true;
            floodTime[nextR][nextC] = time + 1;
        }
    }
}

// 고슴도치 BFS
void bfs(int r, int c) {
    SQ.push({r, c, 0});
    check[r][c][1] = true;
    while (!SQ.empty()) {
        int currR = SQ.front().r, currC = SQ.front().c, time = SQ.front().time;
        SQ.pop();
        for (int i=0; i<4; ++i) {
            int nextR = currR + dir[i][0], nextC = currC + dir[i][1];
            if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
            if (G[nextR][nextC] == 'D') {
                cout << time + 1 << "\n";
                return;
            }
            if (check[nextR][nextC][1]) continue;
            if (G[nextR][nextC] == 'X') continue;
            if (time + 1 >= floodTime[nextR][nextC] && check[nextR][nextC][0] == true) continue;
            SQ.push({nextR, nextC, time+1});
            check[nextR][nextC][1] = true;
        }
    }
    cout << "KAKTUS" << "\n";
}

void solve(int r, int c) {
    waterBfs();
    // for (int i=0; i<R; ++i) {
    //     for (int j=0; j<C; ++j) {
    //         cout << floodTime[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    bfs(r, c);
}

void getInput() {
    cin >> R >> C;
    int r = 0, c = 0;
    for (int i=0; i<R; ++i) {
        string str; cin >> str;
        for (int j=0; j<C; ++j) {
            char temp = str[j];
            G[i][j] = temp;
            if (temp == '*') vec.push_back({i, j});
            else if (temp == 'S') r = i, c = j;
        }
    }
    solve(r, c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}