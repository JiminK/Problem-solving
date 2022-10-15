#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

const int dy[] = { 0,-1,-1,-1,0,1,1,1 };
const int dx[] = { -1,-1,0,1,1,1,0,-1 };
const int sdy[] = { 0,-1,0,1,0 };
const int sdx[] = { 0,0,-1,0,1 };

using namespace std;

struct FISH {
	int y, x;
	int d;
	bool alive = true;
};
vector<FISH> fish;

struct SHARK {
	int y, x;
};
SHARK shark;

struct MAP_INFO {
	vector<int> fnum;
	int scent_time = 0;
};
MAP_INFO map[5][5];

int tmp[5][5];

int pre_size = 0;
int Time = 1;
int M, S;
int ret = 0;
int selected[3];

vector<pair<int, int>> fishNum;

bool compare(pair<int, int>& A, pair<int, int>& B) {
	if (A.first == B.first)
		return A.second < B.second;
	else return A.first > B.first;
}

void complete_copy() {
	for (int i = pre_size; i < fish.size(); i++) {
		int y = fish[i].y;
		int x = fish[i].x;
		map[y][x].fnum.push_back(i);
	}
}

void remove_scent() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (Time - map[i][j].scent_time == 2) {
				map[i][j].scent_time = 0;
			}
		}
	}
	Time++;
}

void move() {

	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			tmp[i][j] = map[i][j].fnum.size();

	int cnt = 0, order = 0;

	int y = shark.y;
	int x = shark.x;

	for (int i = 0; i < 3; i++) {
		int dir = selected[i];

		int ny = y + sdy[dir];
		int nx = x + sdx[dir];

		if (ny <= 0 || nx <= 0 || ny > 4 || nx > 4) return;
		if (tmp[ny][nx] != 0) {
			cnt += map[ny][nx].fnum.size();
			tmp[ny][nx] = 0;
		}

		y = ny;
		x = nx;
	}

	order = selected[0] * 100 + selected[1] * 10 + selected[2];
	fishNum.push_back(make_pair(cnt, order));
}

void dfs(int cnt) {
	if (cnt == 3) {
		move();
		return;
	}
	for (int i = 1; i <= 4; i++) {
		selected[cnt] = i;
		dfs(cnt + 1);
	}
}

void move_shark() {
	/*
	choose 3directions &
	order by removed fish num, direction
	*/
	dfs(0);
	sort(fishNum.begin(), fishNum.end(), compare);

	int cnt = fishNum[0].first;
	int order = fishNum[0].second;
	int ny, nx;
	int divisor = 100;
	for (int i = 0; i < 3; i++) {
		int d = (order / divisor);
		order = order - (d * divisor);
		divisor /= 10;

		ny = shark.y + sdy[d];
		nx = shark.x + sdx[d];

		if (map[ny][nx].fnum.size() != 0) {

			for (int j = 0; j < map[ny][nx].fnum.size(); j++) {
				int f = map[ny][nx].fnum[j];
				fish[f].alive = false;
			}
			map[ny][nx].fnum.clear();
			map[ny][nx].scent_time = Time;
		}

		shark.y = ny;
		shark.x = nx;
	}
}

void update_map() {
	//clear map
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 4; j++)
			map[i][j].fnum.clear();

	//add fish to map
	for (int i = 0; i < pre_size; i++) {
		if (fish[i].alive == false) continue;
		int y = fish[i].y;
		int x = fish[i].x;

		map[y][x].fnum.push_back(i);
	}
}

void move_fish() {
	for (int i = 0; i < pre_size; i++) {
		if (fish[i].alive == false) continue;

		int y = fish[i].y;
		int x = fish[i].x;
		int d = fish[i].d;

		for (int j = 0; j < 8; j++) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny > 0 && nx > 0 && ny <= 4 && nx <= 4) {
				if (map[ny][nx].scent_time == 0) {
					if (!(ny == shark.y && nx == shark.x)) {
						fish[i].y = ny;
						fish[i].x = nx;
						break;
					}
				}
			}
			d = d - 1;
			if (d < 0) d = 7;
		}
		fish[i].d = d;
	}
}

void start_copy() {
	pre_size = fish.size();
	int idx = pre_size;
	for (int i = 0; i < pre_size; i++) {
		if (fish[i].alive == false) continue;
		int y = fish[i].y;
		int x = fish[i].x;
		int d = fish[i].d;
		fish.push_back({ y,x,d,true });
	}
}

void solution() {
	while (S--) {
		start_copy();
		move_fish();
		update_map();
		move_shark();
		remove_scent();
		complete_copy();
		fishNum.clear();
	}
}

void input() {
	cin >> M >> S;
	for (int i = 0; i < M; i++) {
		int y, x, d;
		cin >> y >> x >> d;
		fish.push_back({ y,x,d - 1,true });
	}

	int sy, sx;
	cin >> sy >> sx;
	shark.y = sy;
	shark.x = sx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();
	solution();

	int cnt = 0;
	for (int i = 0; i < fish.size(); i++) {
		if (fish[i].alive == true) cnt++;
	}
	cout << cnt << "\n";
}

// ÃâÃ³: https://velog.io/@kimmy/Baekjoon-23290-Simulation-BFS-DFS-Backtracking%EB%A7%88%EB%B2%95%EC%82%AC-%EC%83%81%EC%96%B4%EC%99%80-%EB%B3%B5%EC%A0%9C-c