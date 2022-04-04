#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 100

int n, m;
int a, b, x, y;
bool family[MAX_N + 1][MAX_N + 1];
queue<pair<int, int> > q;
bool visited[MAX_N + 1];

int bfs() {
    while (!q.empty()) {
        int idx = q.front().first;
        // cout << idx << " ";
        if (idx == b) {
            return q.front().second;
        }
        for (int i = 1; i < n + 1; ++i) {
            if (family[idx][i] == 1 && visited[i] == 0) {
                // cout << i << " ";
                q.push(make_pair(i, q.front().second + 1));
                // q.push({i, q.front().second + 1}); --> g++ -o 2644.out 2644.cpp -std=c++17
                visited[i] = 1;
            }
        }
        q.pop();
        // cout << "\n";
        // cout << cnt << " ";
    }
    return -1;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    cin >> n >> a >> b >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        family[x][y] = 1;
        family[y][x] = 1;
    }
    q.push(make_pair(a, 0));
    visited[a] = 1;
    // q.push({a, 0});
    cout << bfs() << "\n";

    return 0;
}