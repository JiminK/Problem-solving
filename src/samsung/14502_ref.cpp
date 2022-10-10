#include <iostream>

#define MAX_N 8

using namespace std;

int N, M;
int arr[MAX_N + 1][MAX_N + 1];
int tempArr[MAX_N + 1][MAX_N + 1];
bool check[MAX_N + 1][MAX_N + 1];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int wallCnt;

void setWall(int r, int c) { // dfs
    if (wallCnt == 3) {
        // virus dfs
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                if (tempArr[i][j] == 2) {
                    virus(i, j); 
                }                       
            }   
        }
        return;
    }
    // set wall
    for (int i=r; i<N; ++i) {
		for (int j=0; j<M; ++j) {
			if (tempArr[i][j] == 0) {
                tempArr[i][j] = 1;
                wallCnt++;
				setWall(i, j);
                // 원상복귀 시켜주기 !!
                tempArr[i][j] = 0;
            }
		}
	}
    init();
    
}

void virus(int r, int c) { // dfs
    if (check[r][c]) return;
    check[r][c] = 1;
    for (int i=0; i<4; ++i) {
        int nextR = r + dir[i][0], nextC = c + dir[i][1];
        if (check[nextR][nextC]) continue;
        if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M) continue;
        virus(nextR, nextC);
    }
}

void init() {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            tempArr[i][j] = arr[i][j];
        }
    }
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            check[i][j] = 0;
        }
    }

    wallCnt = 0;
}

void getInput() {
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> arr[i][j];
            // copy
            tempArr[i][j] = arr[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();

    return 0;
}