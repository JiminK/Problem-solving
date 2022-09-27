#include <iostream>
#include <queue>
#include <vector>

#define MAX_N 1000

using namespace std;

int M, N;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int visited[MAX_N + 1][MAX_N + 1];
int box[MAX_N + 1][MAX_N + 1];
queue<pair<pair<int, int>, int>> tomato;
int cost;

void bfs() {
    while (!tomato.empty()) {
		int currX = tomato.front().first.first;
		int currY = tomato.front().first.second;
		cost = tomato.front().second;
        tomato.pop();

		for (int i=0; i<4; ++i) {
            int nextX = currX + dir[i][0];
			int nextY = currY + dir[i][1];
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
			if (box[nextX][nextY] == -1 || visited[nextX][nextY] == 1) continue;
            visited[nextX][nextY] = 1;
            box[nextX][nextY] = 1;
            tomato.push({{nextX, nextY}, cost+1});
		}
	}
}

void check() {
	for (int i=0; i<N; ++i) {
		for (int j=0; j<M; ++j) {
			if (box[i][j] == 0) {
				cost = -1; 
				break;
			}
		}
	}
}

void getInput() {
    cin >> M >> N;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
	            visited[i][j] = true;
				tomato.push(make_pair(make_pair(i, j), 0));
			}
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    getInput();
    bfs();
    check();
    cout << cost << "\n";

    return 0;
}