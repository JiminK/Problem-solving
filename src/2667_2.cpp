#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int map[26][26];
vector<int> danji; // size 출력, 원소 오름차순 출력
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool visited[26][26];
int danjiNum;

void dfs(int r, int c) {
    if (visited[r][c]) return;
    visited[r][c] = 1;
    for (int i=0; i<4; ++i) {
        int nextR = r + dir[i][0], nextC = c + dir[i][1];
        if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= N) continue;
        if (map[nextR][nextC] == 0) continue;
        if (visited[nextR][nextC]) continue;
        dfs(nextR, nextC);
        danjiNum++;
    }
}

void init() {
    // for (int i=0; i<N; ++i) {
    //     for (int j=0; j<N; ++j) {
    //         visited[i][j] = 0;
    //     }
    // }
    danjiNum = 0;
}

void solve() {
    for (int r=0; r<N; ++r) {
        for (int c=0; c<N; ++c) {
            init();
            if (map[r][c] == 0 || visited[r][c] == 1) continue;
            dfs(r, c);
            // cout << "final cnt >>>>>>>> " << danjiNum+1 << "\n";
            danji.push_back(danjiNum+1);
        }   
    }
    cout << danji.size() << "\n";
    sort(danji.begin(), danji.end());
    for (int i=0; i<danji.size(); ++i) {
        cout << danji[i] << "\n";
    }
}

void getInput() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        string tempStr; cin >> tempStr;
        for (int j=0; j<N; ++j) {
            map[i][j] = tempStr[j] - '0';
        }
    }
    solve();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}