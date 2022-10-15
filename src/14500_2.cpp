#include <iostream>
#include <queue>

#define MAX_N 500
#define MAX_M 500

using namespace std;

int N, M;
int arr[MAX_N+1][MAX_M+1];
bool visited[MAX_N+1][MAX_M+1];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // r, d, l, u 
int sum;
int maxSum;

void init() {
    sum = 0;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            visited[i][j] = false;
        }
    }
}

void countSum(int r, int c, int cnt) { //  , cnt: 4개 카운팅 
    if (visited[r][c]) return;
    visited[r][c] = true;
    sum += arr[r][c];
    cout << sum << "\n";
    if (cnt == 4) {
        if (sum > maxSum) maxSum = sum;
        return;
    }
    
    for (int i = 0; i < 4; ++i) {
        int nextR = r + dir[i][0], nextC = c + dir[i][1];
        // bound check
        if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= M) continue;
        countSum(nextR, nextC, cnt+1);        
    }
}

void getInput() {
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> arr[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            countSum(i, j, 0);
            init();
        }
    }
    cout << maxSum << "\n";

    return 0;
}