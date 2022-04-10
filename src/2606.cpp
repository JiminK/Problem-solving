#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 100

int n, k, cnt;
queue<int> q;
bool checked[MAX_N + 1][MAX_N + 1];
bool visited[MAX_N + 1];

int bfs() {
    while (!q.empty()) {
        int idx = q.front();

        for (int i = 2; i < n + 1; ++i) {
            if (checked[idx][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
                cnt++;
            }
        }
        q.pop();
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int a, b; cin >> a >> b;
        checked[a][b] = 1;
        checked[b][a] = 1; // 양방향이라서!
    }
    q.push(1); 
    cout << bfs() << "\n";

    return 0;
}