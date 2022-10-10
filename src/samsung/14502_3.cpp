#include <iostream>
#include <queue>
#include <vector>

#define MAX_N 8

using namespace std;

int N, M;
int map[MAX_N + 1][MAX_N + 1];
int tempMap[MAX_N + 1][MAX_N + 1];
queue <int> qR, qC;
vector <int> zeroR, zeroC;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // r, d, l, u
bool check[MAX_N + 1][MAX_N + 1];
int maxCnt, cntZero;

void bfs() {
    while (!qR.empty() && !qC.empty()) {
        int r = qR.front(), c = qC.front();
        qR.pop(); qC.pop();
        tempMap[r][c] = 2;
        for (int i=0; i<4; ++i) {
            int nextR = r + dir[i][0], nextC = c + dir[i][1];
            if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M) continue;
            if (!check[nextR][nextC] && tempMap[nextR][nextC] == 0) {
                qR.push(nextR); qC.push(nextC);
            }
        }
    }
}

void cntZeros() {
    cntZero = 0;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (tempMap[i][j] == 0) cntZero++;
        }
    }
    
    // 최대 0 개수 찾기
    maxCnt = max(cntZero, maxCnt);

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            tempMap[i][j] = map[i][j];
        }
    }
}

void setWall() {
    // 벽 세우기
    maxCnt = -1; 
    for (int i=0; i<zeroR.size()-2; ++i) {
        for (int j=i+1; j<zeroR.size()-1; ++j) {
            for (int k=j+1;  k<zeroR.size(); ++k) {
                // int wallR1 = zeroR[i], wallC1 = zeroC[i];
                tempMap[zeroR[i]][zeroC[i]] = 1;
                tempMap[zeroR[j]][zeroC[j]] = 1;
                tempMap[zeroR[k]][zeroC[k]] = 1;

                // bfs 
                for (int l=0; l<N; ++l) {
                    for (int p=0; p<M; ++p) {
                        if (tempMap[l][p] == 2) {
                            qR.push(l); qC.push(p);
                            bfs();     
                        }                       
                    }   
                }
                // cout << "zeroR[i] " << zeroR[i] << ", zeroC[i] " << zeroC[i] << "\n";
                // 0 개수 세기
                cntZeros();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                zeroR.push_back(i);
                zeroC.push_back(j);
            }
        }
    }
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            tempMap[i][j] = map[i][j];
        }
    }

    setWall();
    cout << maxCnt << "\n";

    return 0;
}