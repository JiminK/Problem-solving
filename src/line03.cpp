#include <string>
#include <vector>

#define MAX_N 30
#define MAX_M 1000000000

using namespace std;

int fireDir[8][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
int iceDir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
bool fireVisited[MAX_N + 1][MAX_N + 1];
bool iceVisited[MAX_N + 1][MAX_N + 1];

void fireDfs(int r, int c, vector<vector<long long>> answer, int n) {
    if (fireVisited[r][c]) return;
    fireVisited[r][c] = 1;
    answer[r][c]++;
    for (int i=0; i<8; ++i) {
        int nextR = r + fireDir[i][0], nextC = c + fireDir[i][1];
        if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= n) continue;
        fireDfs(nextR, nextC, answer, n);
    }
}

void iceDfs(int r, int c, vector<vector<long long>> answer, int n) {
    if (iceVisited[r][c]) return;
    iceVisited[r][c] = 1;
    answer[r][c]++;
    for (int i=0; i<8; ++i) {
        int nextR = r + iceDir[i][0], nextC = c + iceDir[i][1];
        if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= n) continue;
        iceDfs(nextR, nextC, answer, n);
    }
}

void init(int n) {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            fireVisited[i][j] = 0;
            iceVisited[i][j] = 0;
        }
    }
}

vector<vector<long long>> solution(int n, int m, vector<vector<int>> fires, vector<vector<int>> ices) {
    vector<vector<long long>> answer(n, vector<long long>(n, 0));

    for (int j=0; j<m; ++j) {
        init(n);
        for (int i=0; i<fires.size(); ++i) {
            fireDfs(fires[i][0], fires[i][1], answer, n);
        }
        for (int i=0; i<ices.size(); ++i) {
            iceDfs(ices[i][0], ices[i][1], answer, n);
        } 
    }
     

    return answer;
}