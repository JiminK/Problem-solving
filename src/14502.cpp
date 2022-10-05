#include <iostream>
#include <queue>
#include <vector>

#define MAX_N 8
#define MAX_M 8

using namespace std;

int n, m;
int G[MAX_N + 1][MAX_M + 1];
int tmpG[MAX_N + 1][MAX_M + 1];
queue <int> qR;
queue <int> qC;
vector <int> zeroR;
vector <int> zeroC;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // r, d, l, u
bool visited[MAX_N + 1][MAX_M + 1];

void printTemp() {
    cout << "\n=======\n";
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cout << tmpG[r][c] << " ";
        } cout << "\n";
    }
}

void bfs() {
    while (!qR.empty() && !qC.empty()) {
        int r = qR.front(), c = qC.front();
        qR.pop(); qC.pop();
        tmpG[r][c] = 2;
        for (int i = 0; i < 4; ++i) {
            int nextR = r + dir[i][0], nextC = c + dir[i][1];
            if (nextR < 0 || nextC < 0 || nextR >= n || nextC >= m)
                continue;
            if (!visited[nextR][nextC] && tmpG[nextR][nextC] == 0) {
                qR.push(nextR); qC.push(nextC);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> G[i][j];
            if (G[i][j] == 0) {
                zeroR.push_back(i);
                zeroC.push_back(j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            tmpG[i][j] = G[i][j];
        }
    }

    // 벽 세우기 
    int maxCnt = -1;
    for (int i = 0; i < zeroR.size() - 2; ++i) {
        for (int j = i + 1; j < zeroR.size() - 1; ++j) {
            for (int k = j + 1;  k < zeroR.size(); ++k) {
                // int wallR1 = zeroR[i], wallC1 = zeroC[i];
                tmpG[zeroR[i]][zeroC[i]] = 1;
                tmpG[zeroR[j]][zeroC[j]] = 1;
                tmpG[zeroR[k]][zeroC[k]] = 1;

                // bfs 
                for (int l = 0; l < n; ++l) {
                    for (int p = 0; p < m; ++p) {
                        if (tmpG[l][p] == 2) {
                            qR.push(l); qC.push(p);
                            bfs();     
                        }                       
                    }   
                }
                // cout << "zeroR[i] " << zeroR[i] << ", zeroC[i] " << zeroC[i] << "\n";
                // printTemp();
                // 0 개수 세기
                int cntZeors = 0;
                for (int l = 0; l < n; ++l) {
                    for (int p = 0; p < m; ++p) {
                        if (tmpG[l][p] == 0) cntZeors++;
                    }
                }
                
                // 최대 0 개수 찾기
                maxCnt = max(cntZeors, maxCnt);

                for (int l = 0; l < n; ++l) {
                    for (int p = 0; p < m; ++p) {
                        tmpG[l][p] = G[l][p];
                    }
                }
            }
        }
    }
    cout << maxCnt << "\n";

    return 0;
}